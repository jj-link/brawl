#include <gf/gf_scene.h>
#pragma force_active on

extern "C" {
extern char lbl_1_data_1C48[];

void fn_1_8060(gfScene* self) {
    const char* base = lbl_1_data_1C48;
    self->setLoadModule(base + 0x10, false);
    self->setLoadModule(base + 0x24, false);
    self->setLoadModule(base + 0x44, false);
}
}
