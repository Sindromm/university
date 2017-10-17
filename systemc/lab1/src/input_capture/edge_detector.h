#pragma once

#include <systemc.h>

SC_MODULE(EdgeDetector) {
    enum ed_icm_conf {
        any,
        pos,
        neg
    };

    sc_in<sc_uint<3>>   icm_i;
    sc_in<bool>         ins_i;
    sc_out<bool>        ins_o;

    SC_HAS_PROCESS(EdgeDetector);

    EdgeDetector(sc_module_name nm);
    ~EdgeDetector() = default;

    private:
    bool reg_ins_o;

    void on_ins_changed();
    ed_icm_conf get_conf();
};
