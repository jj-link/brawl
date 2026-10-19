#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_6048[0x60];

extern "C" void fn_1_1CCBC(gfScene* self) {
    self->setLoadModule(lbl_1_data_6048 + 0xc, false);
    self->setLoadModule(lbl_1_data_6048 + 0x28, false);
    self->setLoadModule(lbl_1_data_6048 + 0x40, false);
}
