#include <gf/gf_scene.h>
#pragma force_active on

extern const char lbl_1_data_1DD8[];
extern const char lbl_1_data_1DEC[];

extern "C" void fn_1_8A34(gfScene* self) {
    self->setLoadModule(lbl_1_data_1DD8, false);
    self->setLoadModule(lbl_1_data_1DEC, false);
}
