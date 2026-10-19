#include <gf/gf_scene.h>
#pragma force_active on

extern "C" const char lbl_1_data_4A6C[];
extern "C" const char lbl_1_data_4A80[];

extern "C" void fn_1_F298(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_4A6C, false);
    scene->setLoadModule(lbl_1_data_4A80, false);
}
