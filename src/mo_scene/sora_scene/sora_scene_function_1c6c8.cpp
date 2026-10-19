#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern const char lbl_1_data_5F5C[];
extern const char lbl_1_data_5F74[];

extern "C" void fn_1_1C6C8(gfScene* self) {
    self->setLoadModule(lbl_1_data_5F5C, false);
    self->setLoadModule(lbl_1_data_5F74, false);
}
