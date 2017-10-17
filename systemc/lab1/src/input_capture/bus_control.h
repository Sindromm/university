#pragma once

#include <systemc.h>

SC_MODULE(BusControl) {
    enum ic_addresses {
        icconf = 0x18,
        icbuf = 0x1C
    };

    sc_in<bool>         clk_i;
    sc_in<sc_uint<32>>  addr_bi;
    sc_in<sc_uint<32>>  data_bi;
    sc_out<sc_uint<32>> data_bo;
    sc_in<bool>         wr_i;
    sc_in<bool>         rd_i;

    sc_in<sc_uint<32>>  icconf_i;
    sc_out<sc_uint<32>> icconf_o;
    sc_in<sc_uint<32>>  icbuf_i;
    sc_out<bool>        fifo_rd_o;

    SC_HAS_PROCESS(BusControl);

    BusControl(sc_module_name nm);
    ~BusControl() = default;

    private:
    void on_rd_i();

    void bus_read();
    void bus_write();

    bool flag_rd_i;
};
