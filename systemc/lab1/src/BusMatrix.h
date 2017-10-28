#pragma once

#include "systemc.h"
#include <vector>

#define FIRST_TIMER_OFFSET 0x0
#define SECOND_TIMER_OFFSET 0xC
#define NUMBER_OF_SLAVES 3

SC_MODULE(BusMatrix) {
    sc_in<bool>         clk_i;
    sc_in<sc_uint<32>>  addr_bi;
    sc_in<bool>         rd_i;
    sc_in<bool>         wr_i;
    sc_out<sc_uint<32>> data_bo;

    sc_in<sc_uint<32>>  timer1_data_bi;
    sc_out<bool>        timer1_rd_o;
    sc_out<bool>        timer1_wr_o;
    sc_in<sc_uint<32>>  timer2_data_bi;
    sc_out<bool>        timer2_rd_o;
    sc_out<bool>        timer2_wr_o;
    sc_in<sc_uint<32>>  input_capture_data_bi;
    sc_out<bool>        input_capture_rd_o;
    sc_out<bool>        input_capture_wr_o;

    SC_HAS_PROCESS(BusMatrix);
    
    BusMatrix(sc_module_name nm);
    ~BusMatrix() = default;
    
private:
    void on_change();
    void read();
    void send(size_t slave_i);

    std::vector<sc_in<sc_uint<32>> *>   slaves_data_bi;
    std::vector<sc_out<bool> *>         slaves_rd_o;
    std::vector<sc_out<bool> *>         slaves_wr_o;

    bool reg_timer_rd_flag[3];
};
