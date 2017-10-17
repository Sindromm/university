#include "prescaler.h"

Prescaler::Prescaler(sc_module_name nm)
        :sc_module(nm),
         clk_i("clk_i"),
         icm_i("icm_i"),
         ins_i("ins_i"),
         ins_o("ins_o"),

         reg_counter(0)
{
    ins_o.initialize(0);
    reg_prev_ins = ins_i.read();
    reg_prev_conf = get_conf();

    SC_METHOD(on_clk);
    sensitive << clk_i.pos();
}

void Prescaler::on_clk() {
    bool temp_ins = ins_i.read();
    prescaler_icm_conf temp_conf = get_conf();

    if (temp_conf == off || reg_prev_conf != temp_conf) {
        reg_counter = 0;
    } else if (temp_ins != reg_prev_ins) {
        reg_counter++;
        if (reg_counter < 2) {
            ins_o.write(temp_ins);
        } else if (reg_counter >= temp_conf) {
            reg_counter = 0;
        }
    }
    reg_prev_ins = temp_ins;
    reg_prev_conf = temp_conf;
}

Prescaler::prescaler_icm_conf Prescaler::get_conf() {
    sc_uint<3> temp_icm_i = icm_i.read();
    if (temp_icm_i == 0x0) {
        return off;
    } else if (temp_icm_i.range(2, 1) == 0x1) {
        return any_4nd;
    } else if (temp_icm_i.range(2, 1) == 0x3) {
        return any_16th;
    } else {
        return any;
    }
}

