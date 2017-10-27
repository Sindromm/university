#include "mips32.h"
#include "Timer.h"
#include "BusMatrix.h"
#include "InputCapture.h"
#include "Signal.h"

int sc_main(int argc, char* argv[]) {
    
    MIPS32 mips32_core("mips32");
    BusMatrix data_input_mux("data_input_mux");

    Timer timer1("timer1", FIRST_TIMER_OFFSET);
    Timer timer2("timer2", SECOND_TIMER_OFFSET);
    InputCapture input_capture("input_capture");

    Signal signal_block("signal_block");

    sc_clock clk("clk", sc_time(10, SC_NS));
    sc_signal<sc_uint<32>> addr;
    sc_signal<sc_uint<32>> data_mips32_bo;
    sc_signal<sc_uint<32>> data_mips32_bi;
    sc_signal<bool> wr;
    sc_signal<bool> rd;

    sc_signal<sc_uint<32>> bo_timer1_dim;
    sc_signal<sc_uint<32>> bo_timer2_dim;
    sc_signal<sc_uint<32>> bo_ic_dim;

    sc_signal<sc_uint<32>> tval_timer1_ic;
    sc_signal<sc_uint<32>> tval_timer2_ic;

    sc_signal<bool> signal;

    mips32_core.clk_i(clk);
    mips32_core.addr_bo(addr);
    mips32_core.data_bi(data_mips32_bi);
    mips32_core.data_bo(data_mips32_bo);
    mips32_core.wr_o(wr);
    mips32_core.rd_o(rd);

    data_input_mux.clk_i(clk);
    data_input_mux.addr_bi(addr);
    data_input_mux.rd_i(rd);
    data_input_mux.wr_i(wr);
    data_input_mux.data_bo(data_mips32_bi);
    data_input_mux.slaves_data_bi = (std::array<sc_in<sc_uint<32>>>){addr, addr, addr};
    data_input_mux.slaves_data_bo;
    data_input_mux.slaves_data_bi(bo_timer2_dim);

    timer1.clk_i(clk);
    timer1.addr_bi(addr);
    timer1.data_bi(data_mips32_bo);
    timer1.data_bo(bo_timer1_dim);
    timer1.wr_i(wr);
    timer1.rd_i(rd);
    timer1.tval_o(tval_timer1_ic);

    timer2.clk_i(clk);
    timer2.addr_bi(addr);
    timer2.data_bi(data_mips32_bo);
    timer2.data_bo(bo_timer2_dim);
    timer2.wr_i(wr);
    timer2.rd_i(rd);
    timer2.tval_o(tval_timer2_ic);

    signal_block.data_o(signal);

    input_capture.clk_i(clk);
    input_capture.ins_i(signal);
    input_capture.addr_bi(addr);
    input_capture.data_bi(data_mips32_bo);
    input_capture.data_bo(bo_ic_dim);
    input_capture.wr_i(wr);
    input_capture.rd_i(rd);
    input_capture.timer1_i(tval_timer1_ic);
    input_capture.timer2_i(tval_timer2_ic);

    sc_trace_file *wf = sc_create_vcd_trace_file("wave");
    wf->set_time_unit(100, SC_PS);
    sc_trace(wf, clk, "clk");
    sc_trace(wf, addr, "addr_bo");
    sc_trace(wf, data_mips32_bi, "data_bi");
    sc_trace(wf, data_mips32_bo, "data_bo");
    sc_trace(wf, wr, "wr");
    sc_trace(wf, rd, "rd");

    sc_trace(wf, input_capture.icconf_icconf_fifo, "ic.icconf_icconf_fifo");
    sc_trace(wf, input_capture.icm_from_icconf, "ic.icm_from_icconf");
    sc_trace(wf, input_capture.ictmr_from_icconf, "ic.ictmr_from_icconf");
    sc_trace(wf, input_capture.icconf_fifo_icconf, "ic.icconf_fifo_icconf");
    sc_trace(wf, input_capture.ins_ed_prescaler, "ic.ins_ed_prescaler");
    sc_trace(wf, input_capture.ins_prescaler_fifo, "ic.ins_prescaler_fifo");
    sc_trace(wf, input_capture.tval_tc_fifo, "ic.tval_tc_fifo");
    sc_trace(wf, input_capture.icbne_fifo_icconf, "ic.icbne_fifo_icconf");
    sc_trace(wf, input_capture.icov_fifo_icconf, "ic.icov_fifo_icconf");
    sc_trace(wf, bo_timer1_dim, "mux_timer1_in");
    sc_trace(wf, bo_timer2_dim, "mux_timer2_in");
    sc_trace(wf, bo_ic_dim, "mux_ic_in");

    sc_trace(wf, tval_timer1_ic, "tval1_out");
    sc_trace(wf, tval_timer2_ic, "tval2_out");

    sc_trace(wf, signal, "signal");

    sc_start();

 
    sc_close_vcd_trace_file(wf);
    
    return(0);
    
}
