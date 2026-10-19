#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern char lbl_1_data_6E0[];

extern "C" bool fn_1_50B0(gfScene* self) {
    return self->setLoadModule(lbl_1_data_6E0, false);
}
