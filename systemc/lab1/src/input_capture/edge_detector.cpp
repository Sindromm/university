#include "edge_detector.h"

EdgeDetector::EdgeDetector(sc_module_name nm)
        :sc_module(nm),
         icm_i("icm_i"),
         ins_i("ins_i"),
         ins_o("ins_o"),

         reg_ins_o(0)
{
    ins_o.initialize(0);

    SC_METHOD(on_ins_changed);
    sensitive << ins_i.value_changed();
}

void EdgeDetector::on_ins_changed() {
    bool temp_ins = ins_i.read();
    ed_icm_conf temp_conf = get_conf();

    if (temp_conf == any || temp_conf == pos && temp_ins || temp_conf == neg && !temp_ins) {
        reg_ins_o = !reg_ins_o;
        ins_o.write(reg_ins_o);
    }
}

EdgeDetector::ed_icm_conf EdgeDetector::get_conf() {
    switch (icm_i.read()) {
        case 0x1: {
            return any;
        }
        case 0x2:
        case 0x6:
        case 0x7: {
            return neg;
        }
        default: {
            return pos;
        }
    }
}

