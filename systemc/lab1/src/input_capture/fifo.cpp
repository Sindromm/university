#include "fifo.h"

FIFO::FIFO(sc_module_name nm)
        :sc_module(nm),
         clk_i("clk_i"),
         rd_i("rd_i"),

         ins_i("ins_i"),
         ictmr_i("ictmr_i"),
         icbne_o("icbne_o"),
         icov_o("icov_o"),
         icbuf_o("icbuf_o"),
         tval1_i("tval1_i"),
         tval2_i("tval2_i")
{
    icbne_o.initialize(0);
    icov_o.initialize(0);
    icbuf_o.initialize(0);

    reg_icov = n_full;
    reg_icbne = empty;

    reg_fst_idx = 0;
    reg_next_idx = reg_fst_idx + 1;

    SC_METHOD(on_neg_clk);
    sensitive << clk_i.neg();

    SC_METHOD(push);
    sensitive << ins_i.value_changed();

    SC_METHOD(get);
    sensitive << clk_i.pos() << rd_i.pos();
}

void FIFO::on_neg_clk() {
    reg_icbne = (reg_next_idx - reg_fst_idx == 1) ? empty : n_empty;
    reg_icov = reg_next_idx == reg_fst_idx ? full : n_full;

    icbne_o.write(reg_icbne);
    icov_o.write(reg_icov);
}

void FIFO::push() {
    if (reg_icov == full) {
        return;
    }
    sc_uint<32> temp_value = 0;

    switch (ictmr_i.read()) {
        case off: {
            return;
        }
        case first:
        case second: {
            temp_value.range(15, 0) = tval1_i.read().range(15, 0);
            break;
        }
        case both: {
            temp_value.range(15, 0) = tval1_i.read().range(15, 0);
            temp_value.range(31, 16) = tval2_i.read().range(15, 0);
            break;
        }
    }
    icbuf[reg_next_idx] = temp_value;
    reg_next_idx = get_next_idx(reg_next_idx);
}

void FIFO::get() {
    if (!rd_i.read() || !clk_i.read() || reg_icbne == empty) {
        return;
    }

    icbuf_o.write(icbuf[reg_fst_idx]);
    reg_fst_idx = get_next_idx(reg_fst_idx);
}

int FIFO::get_next_idx(int idx) {
    if (idx == MAX_BUF_IDX) {
        return 0;
    } else {
        return ++idx;
    }
}
