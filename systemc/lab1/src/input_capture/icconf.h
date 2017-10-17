#pragma once

#include <systemc.h>

SC_MODULE(ICCONF) {
    sc_in<sc_uint<32>>  icconf_i;
    sc_out<sc_uint<32>> icconf_o;
    sc_in<bool>         icbne_i;
    sc_in<bool>         icov_i;
    sc_out<sc_uint<3>>  icm_o;
    sc_out<sc_uint<2>>  ictmr_o;

    SC_HAS_PROCESS(ICCONF);

    ICCONF(sc_module_name nm);
    ~ICCONF() = default;

    private:
    void on_change();

    sc_uint<32> reg_icconf;
};
