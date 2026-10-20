#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_15D8[];

extern "C" void fn_1_682C(gfScene* self) {
    char* base = (char*)lbl_1_data_15D8;
    self->setLoadModule(base + 0xC, false);
    self->setLoadModule(base + 0x20, false);
    self->setLoadModule(base + 0x34, false);
    self->setLoadModule(base + 0x48, false);
    self->setLoadModule(base + 0x68, false);
}
