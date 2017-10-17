#pragma once

#include <systemc.h>

#define BUF_SIZE 32
#define MAX_BUF_IDX (BUF_SIZE - 1)

SC_MODULE(FIFO) {
    enum icbne_conf {
        empty   = 0x0,
        n_empty = 0x1
    };

    enum icov_conf {
        n_full  = 0x0,
        full    = 0x1
    };

    enum ictmr_conf {
        off     = 0x0,
        first   = 0x1,
        second  = 0x2,
        both    = 0x3
    };

    sc_in<bool>         clk_i;
    sc_in<bool>         rd_i;

    sc_in<bool>         ins_i;
    sc_in<sc_uint<2>>   ictmr_i;
    sc_out<bool>        icbne_o;
    sc_out<bool>        icov_o;
    sc_out<sc_uint<32>> icbuf_o;
    sc_out<sc_uint<32>> tval1_i;
    sc_out<sc_uint<32>> tval2_i;

    SC_HAS_PROCESS(FIFO);

    FIFO(sc_module_name nm);
    ~FIFO() = default;

    private:
    sc_uint<32> icbuf[BUF_SIZE] = {0};
    int reg_next_idx;
    int reg_fst_idx;

    bool reg_icov;
    bool reg_icbne;

    void on_neg_clk();

    void push();
    void get();

    int get_next_idx(int idx);
};
