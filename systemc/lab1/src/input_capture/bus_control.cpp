#include "bus_control.h"

BusControl::BusControl(sc_module_name nm)
        :sc_module(nm),
         clk_i("clk_i"),
         addr_bi("addr_bi"),
         data_bi("data_bi"),
         data_bo("data_bo"),
         wr_i("wr_i"),
         rd_i("rd_i"),

         icconf_i("icconf_i"),
         icconf_o("icconf_o"),
         icbuf_i("icbuf_i"),
         fifo_rd_o("fifo_rd_o"),

         flag_rd_i(0)
{
    data_bo.initialize(0);
    icconf_o.initialize(0);
    fifo_rd_o.initialize(0);

    SC_METHOD(on_rd_i);
    sensitive << clk_i.value_changed() << rd_i.value_changed();

    SC_METHOD(bus_read);
    sensitive << clk_i.pos() << wr_i.pos();

    SC_METHOD(bus_write);
    sensitive << clk_i.neg();
}

void BusControl::on_rd_i() {
    if (clk_i.read() && rd_i.read()) {
        fifo_rd_o.write(1);
        flag_rd_i = 1;
    } else if (!rd_i.read()) {
        fifo_rd_o.write(0);
        flag_rd_i = 0;
    }
}

void BusControl::bus_read() {
    if (clk_i.read() && wr_i.read()) {
        switch (addr_bi.read()) {
            case icconf: {
                icconf_o.write(data_bi.read());
            }
        }
    }
}

void BusControl::bus_write() {
    if (flag_rd_i) {
        switch (addr_bi.read()) {
            case icconf: {
                data_bo.write(icconf_i.read());
            }
            case icbuf: {
                data_bo.write(icbuf_i.read());
            }
        }
    }
}
