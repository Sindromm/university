#pragma once

#include <systemc.h>

SC_MODULE(Prescaler) {
    enum prescaler_icm_conf {
        off         = 0x0,
        any         = 0x2,
        any_4nd     = 0x8,
        any_16th    = 0x20
    };

    sc_in<bool>         clk_i;
    sc_in<sc_uint<3>>   icm_i;
    sc_in<bool>         ins_i;
    sc_out<bool>        ins_o;

    SC_HAS_PROCESS(Prescaler);

    Prescaler(sc_module_name nm);
    ~Prescaler() = default;

    private:
    bool                reg_prev_ins;
    prescaler_icm_conf  reg_prev_conf;
    sc_uint<5>          reg_counter;

    void on_clk();
    prescaler_icm_conf get_conf();
};
