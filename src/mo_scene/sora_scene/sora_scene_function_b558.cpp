#include <gf/gf_scene.h>
#pragma force_active on

extern "C" const char lbl_1_data_3C68[];
extern "C" const char lbl_1_data_3C84[];

extern "C" void fn_1_B558(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_3C68, false);
    scene->setLoadModule(lbl_1_data_3C84, false);
}
