#include "icconf.h"

ICCONF::ICCONF(sc_module_name nm)
        :sc_module(nm),
         icconf_i("icconf_i"),
         icconf_o("icconf_o"),
         icbne_i("icbne_i"),
         icov_i("icov_i"),
         icm_o("icm_o"),
         ictmr_o("ictmr_o")
{

    SC_METHOD(on_change);
    sensitive << icconf_i.value_changed() << icbne_i.value_changed() << icov_i.value_changed();
}

void ICCONF::on_change() {
    reg_icconf = icconf_i.read();
    reg_icconf[3] = icbne_i.read();
    reg_icconf[4] = icov_i.read();

    icconf_o.write(reg_icconf);
    icm_o.write(reg_icconf.range(2, 0));
    ictmr_o.write(reg_icconf.range(6, 5));
}

