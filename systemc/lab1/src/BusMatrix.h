#pragma once

#include <array>
#include "systemc.h"

#define FIRST_TIMER_OFFSET 0x0
#define SECOND_TIMER_OFFSET 0xC

SC_MODULE(BusMatrix) {
    sc_in<bool>         clk_i;
    sc_in<sc_uint<32>>  addr_bi;
    sc_in<bool>         rd_i;
    sc_in<bool>         wr_i;
    sc_out<sc_uint<32>> data_bi;
    sc_out<sc_uint<32>> data_bo;

    std::array<sc_out<sc_uint<32>>, 3>  slaves_addr_bo;
    std::array<sc_in<sc_uint<32>>, 3>   slaves_data_bi;
    std::array<sc_out<sc_uint<32>>, 3>  slaves_data_bo;
    std::array<sc_out<sc_uint<32>>, 3>  slaves_rd_o;
    std::array<sc_out<sc_uint<32>>, 3>  slaves_wr_o;

    SC_HAS_PROCESS(BusMatrix);
    
    BusMatrix(sc_module_name nm);
    ~BusMatrix() = default;
    
private:
    void on_change();
    void read();
    void send(int slave_i);

    bool reg_timer_rd_flag[3];
};
