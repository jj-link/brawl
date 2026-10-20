#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" unsigned char lbl_1_data_16B8[];

extern "C" void fn_1_6B58(gfScene* self) {
    const char* base = (const char*)lbl_1_data_16B8;
    self->setLoadModule(base + 0x10, false);
    self->setLoadModule(base + 0x24, false);
    self->setLoadModule(base + 0x38, false);
    self->setLoadModule(base + 0x4C, false);
    self->setLoadModule(base + 0x70, false);
}
