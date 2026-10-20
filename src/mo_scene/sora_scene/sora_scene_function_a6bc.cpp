#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_2228[];

extern "C" void fn_1_A6BC(gfScene* self) {
    self->setLoadModule(lbl_1_data_2228 + 0x16CC, false);
    self->setLoadModule(lbl_1_data_2228 + 0x16E0, false);
    self->setLoadModule(lbl_1_data_2228 + 0x16F4, false);
    self->setLoadModule(lbl_1_data_2228 + 0x1714, false);
}
