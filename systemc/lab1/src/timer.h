#pragma once

#include "systemc.h"

SC_MODULE(Timer) {
    enum timer_addresses {
        tmr     = 0x00000000,
        tval    = 0x00000004,
        tconf   = 0x00000008
    };

    enum timer_conf {
        dec = 0x1,
        run = 0x2
    };
    
    sc_in<bool>  clk_i;
    sc_in<int>   addr_bi;
    sc_in<int>   data_bi;
    sc_out<int>  data_bo;
    sc_in<bool>  wr_i;
    sc_in<bool>  rd_i;
    sc_out<int>  tval_o;

    SC_HAS_PROCESS(Timer);
    
    Timer(sc_module_name nm, int start_addr);
    ~Timer() = default;
    
private:
    void tick();
    void bus_read();
    void bus_write();

    bool flag_rd_i;
    void on_rd_i();

    int mem_offset;
    int reg_tmr;
    int reg_tval;
    int reg_tconf;
};
