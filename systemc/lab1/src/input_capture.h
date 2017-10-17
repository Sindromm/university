#pragma once

#include "systemc.h"
#include "input_capture/icconf.h"
#include "input_capture/prescaler.h"
#include "input_capture/edge_detector.h"
#include "input_capture/timers_control.h"
#include "input_capture/fifo.h"
#include "input_capture/bus_control.h"

SC_MODULE(InputCapture) {
    sc_in<bool>         clk_i;
    sc_in<bool>         ins_i;
    sc_in<sc_uint<32>>  addr_bi;
    sc_in<sc_uint<32>>  data_bi;
    sc_out<sc_uint<32>> data_bo;
    sc_in<bool>         wr_i;
    sc_in<bool>         rd_i;

    sc_in<sc_uint<32>>  timer1_i;
    sc_in<sc_uint<32>>  timer2_i;

    SC_HAS_PROCESS(InputCapture);
    
    InputCapture(sc_module_name nm);
    ~InputCapture() = default;
    
private:
    ICCONF          icconf;
    BusControl      bus_control;
    Prescaler       prescaler;
    EdgeDetector    edge_detector;
    TimersControl   timers_control;
    FIFO            fifo;

    sc_signal<sc_uint<32>>  icconf_icconf_bc;
    sc_signal<sc_uint<3>>   icm_from_icconf;
    sc_signal<sc_uint<2>>   ictmr_from_icconf;

    sc_signal<sc_uint<32>>  icconf_bc_icconf;
    sc_signal<bool>         rd_bc_fifo;

    sc_signal<bool>         ins_prescaler_ed;

    sc_signal<bool>         ins_ed_fifo;

    sc_signal<sc_uint<32>>  tval_tc_fifo;

    sc_signal<bool>         icbne_fifo_icconf;
    sc_signal<bool>         icov_fifo_icconf;
    sc_signal<sc_uint<32>>  icbuf_fifo_pc;
};
