#include "aduc812.h"
#include "async.h"
#include "sio.h"
#include "sync.h"
#include "system.h"

//Определяет, является ли символ десятичной цифрой
//Вход: проверяемый символ
//Выход: 0 - не является
//		1 - является
bit IsDigit(unsigned char symb) {
	if ((symb >= 48) && (symb <= 57)) {
		return 1;
	} else {
		return 0;
	}
}


#define ERR_OUT_OF_RANGE "\n\rnumber not 0-99\n\r\0"
#define ERR_INVALID_CHAR "\n\rinvalid operator\n\r\0"
#define READ_OK 0
#define READ_OUT_OF_RANGE_ERROR 1
#define READ_INVALID_CHAR_ERROR 2

//Функция последовательно считывает до 2х символов из последовательного канала,
//пока не встретиться оператор и преобразует их в 2х значное десятичное число
//Вход: 	signed char* num - указатель на число (используется для возврата
//результата)
// 			signed char operator - оператор
//Выход: 	результат выполнения операции
signed char ReadNumber(signed char *num, signed char operator) {
	signed char c = 0, i = 0;

	*num = 0;
	for (i = 0; i < 3; i++) {
		c = 0;
		while (!c) {
			if (GetDIP() != 128)
				break;
			c = ReadUART();
		}
		if (GetDIP() != 128)
			break;
		WriteUART(c);
		if (c == operator) {
			return READ_OK;
		}
		if (!IsDigit(c)) {
			return READ_INVALID_CHAR_ERROR;
		}
		if (i > 1) {
			return READ_OUT_OF_RANGE_ERROR;
		}
		*num *= 10;
		*num += c & 0x0F;
	}
	return READ_OK;
}

//Функция преобразует десятичную строку в массив ASCII - симыволов,
//и последовательно отправляет элементы массива в последовательный канал
//Вход: unsigned char res - десятичное число
//Выход: нет
void ResultOutput(unsigned char res) {
	unsigned char rr[4], c;
	char i = 0;
	bit isNegative = 0;
	if ((res & 0x80) == 0x80) {
		isNegative = 1;
		res = ~res;
		res += 1;
	}

	for (i = 0; i < 3; i++) {
		c = res % 10;
		c |= 0x30;
		rr[i] = c;
		res /= 10;
		if (res == 0)
			break;
	}
	if (isNegative) {
		i++;
		rr[i] = '-';
	}
	for (; i >= 0; i--)
		WriteUART(rr[i]);
}

//Вычитатель
void Calc(void) {
	signed char a = 0, b = 0, res = 0, last_operation = 0;
	if (GetDIP() != 128)
		return;
	last_operation = ReadNumber(&a, '-');
	if (last_operation != READ_OK) {
		// if(last_operation ==
		// READ_INVALID_CHAR_ERROR){APIString(ERR_INVALID_CHAR); return;}
		// if(last_operation ==
		// READ_OUT_OF_RANGE_ERROR){APIString(ERR_OUT_OF_RANGE); return;}
		if (last_operation == READ_INVALID_CHAR_ERROR) {
			APIString(ERR_INVALID_CHAR);
			return;
		}
		if (last_operation == READ_OUT_OF_RANGE_ERROR) {
			APIString(ERR_OUT_OF_RANGE);
			return;
		}
	}
	if (GetDIP() != 128)
		return;

	last_operation = ReadNumber(&b, '=');
	if (last_operation != READ_OK) {
		// if(last_operation ==
		// READ_INVALID_CHAR_ERROR){APIString(ERR_INVALID_CHAR); return;}
		// if(last_operation ==
		// READ_OUT_OF_RANGE_ERROR){APIString(ERR_OUT_OF_RANGE); return;}
		if (last_operation == READ_INVALID_CHAR_ERROR) {
			APIString(ERR_INVALID_CHAR);
			return;
		}
		if (last_operation == READ_OUT_OF_RANGE_ERROR) {
			APIString(ERR_OUT_OF_RANGE);
			return;
		}
	}
	if (GetDIP() != 128)
		return;

	res = a - b;
	ResultOutput(res);
	WriteUART('\n');
	WriteUART('\r');
}

unsigned char transform_char(unsigned char c) {
	if ('a' <= c && c <= 'z') {
		return c;
	}
	else if ('A' <= c && c <= 'Z') {
		return c;
	}
	else if (0x30 <= c && c <= 0x3F) {  //  ..ï  ..ï
		return c + 0x70;
	}
	else if (0x40 <= c && c <= 0x4F) {  //  ..ï  ..ï
		return c + 0xA0;
	}
	else if (c == 0x01) {
		return 0xF1;
	}
	else {
		return c;
	}
}

void main(void) {
	unsigned char c;
	unsigned char i = 0;
	unsigned char k = 0;

	init_sio(S4800);
	while (1) {
		if (GetDIP() == 128) {
			ES = 1;
			EA = 1;
			while (1) {
				Calc();
				if (GetDIP() != 128) {
					ES = 0;
					break;
				}
			}
		}
		if (GetDIP() == 1) {
			ES = 0;
			EA = 0;
			while (1) {
				if (rsiostat()) {
					c = rsio();
					for(k = 0; k < 3; k++) {
						wsio(transform_char(c) + k);
					}
					wsio('\r');
					wsio('\n');
					if (GetDIP() != 1)
						break;
				}
			}
		}
	}
}
