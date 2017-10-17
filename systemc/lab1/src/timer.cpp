#include "timer.h"

Timer::Timer(sc_module_name nm, int offset)
        :sc_module(nm),
         clk_i("clk_i"),
         addr_bi("addr_bi"),
         data_bi("data_bi"),
         data_bo("data_bo"),
         wr_i("wr_i"),
         rd_i("rd_i"),
         tval_o("tval_o"),

         mem_offset(offset),
         reg_tmr(0),
         reg_tval(0),
         reg_tconf(0)
{
    data_bo.initialize(0);
    tval_o.initialize(0);

    SC_METHOD(tick);
    sensitive << clk_i.pos() << wr_i.pos();

    SC_METHOD(on_rd_i);
    sensitive << clk_i.value_changed() << rd_i.value_changed();

    SC_METHOD(bus_read);
    sensitive << clk_i.pos() << wr_i.pos();

    SC_METHOD(bus_write);
    sensitive << clk_i.neg();
}

void Timer::tick() {
    if (wr_i.read() && addr_bi.read() == tval) {
        reg_tval = data_bi.read();
        return;
    }

    if (!(reg_tconf & run)) {
        return;
    }

    if (reg_tconf & dec) {
        if (reg_tval > 0) {
            reg_tval--;
        } else {
            reg_tval = reg_tmr;
        }
    }
}

void Timer::on_rd_i() {
    if (clk_i.read() && !rd_i.read()) {
        flag_rd_i = 1;
    } else if(!rd_i.read()) {
        flag_rd_i = 0;
    }
}

void Timer::bus_read() {
    if (wr_i.read() && clk_i.read()) {
        int addr = addr_bi.read() - mem_offset;
        switch (addr) {
            case tconf: {
                reg_tconf = data_bi.read();
                break;
            }
            case tmr: {
                reg_tmr = data_bi.read();
                break;
            }
        }
    } else {
        return;
    }

}

void Timer::bus_write() {
    if (flag_rd_i) {
        int addr = addr_bi.read() - mem_offset;
        switch (addr) {
            case tconf: {
                data_bo.write(reg_tconf);
                break;
            }
            case tmr: {
                data_bo.write(reg_tmr);
                break;
            }
            case tval: {
                data_bo.write(reg_tval);
                break;
            }
        }
    }
}
