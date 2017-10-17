#include "input_capture.h"

InputCapture::InputCapture(sc_module_name nm)
        :sc_module(nm),
         clk_i("clk_i"),
         ins_i("ins_i"),
         addr_bi("addr_bi"),
         data_bi("data_bi"),
         data_bo("data_bo"),
         wr_i("wr_i"),
         rd_i("rd_i"),
         timer1_i("timer1_i"),
         timer2_i("timer2_i"),

         icconf("icconf"),
         bus_control("bus_control"),
         prescaler("prescaler"),
         edge_detector("edge_detector"),
         timers_control("timers_control"),
         fifo("fifo")
{
    icconf.icconf_i(icconf_bc_icconf);
    icconf.icconf_o(icconf_icconf_bc);
    icconf.icbne_i(icbne_fifo_icconf);
    icconf.icov_i(icov_fifo_icconf);
    icconf.icm_o(icm_from_icconf);
    icconf.ictmr_o(ictmr_from_icconf);

    bus_control.clk_i(clk_i);
    bus_control.addr_bi(addr_bi);
    bus_control.data_bi(data_bi);
    bus_control.data_bo(data_bo);
    bus_control.wr_i(wr_i);
    bus_control.rd_i(rd_i);
    bus_control.icconf_i(icconf_icconf_bc);
    bus_control.icconf_o(icconf_bc_icconf);
    bus_control.icbuf_i(icbuf_fifo_pc);
    bus_control.fifo_rd_o(rd_bc_fifo);

    prescaler.clk_i(clk_i);
    prescaler.icm_i(icm_from_icconf);
    prescaler.ins_i(ins_i);
    prescaler.ins_o(ins_prescaler_ed);

    edge_detector.icm_i(icm_from_icconf);
    edge_detector.ins_i(ins_prescaler_ed);
    edge_detector.ins_o(ins_ed_fifo);

    timers_control.timer1_i(timer1_i);
    timers_control.timer2_i(timer2_i);
    timers_control.ictmr_i(ictmr_from_icconf);
    timers_control.tval_o(tval_tc_fifo);

    fifo.clk_i(clk_i);
    fifo.rd_i(rd_bc_fifo);
    fifo.ins_i(ins_ed_fifo);
    fifo.ictmr_i(ictmr_from_icconf);
    fifo.icbne_o(icbne_fifo_icconf);
    fifo.icov_o(icov_fifo_icconf);
    fifo.icbuf_o(icbuf_fifo_pc);
    fifo.tval1_i(tval_tc_fifo);
    fifo.tval2_i(timer2_i);
}
