#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern char lbl_1_data_42B8[];

extern "C" void fn_1_D040(gfScene* self) {
    self->setLoadModule(lbl_1_data_42B8 + 0x14, false);
    self->setLoadModule(lbl_1_data_42B8 + 0x2C, false);
    self->setLoadModule(lbl_1_data_42B8 + 0x40, false);
    self->setLoadModule(lbl_1_data_42B8 + 0x54, false);
}
