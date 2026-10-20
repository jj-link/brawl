#include <gf/gf_scene.h>
#pragma force_active on

extern "C" const char lbl_1_data_4260[];

extern "C" void fn_1_CC2C(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_4260, false);
}
