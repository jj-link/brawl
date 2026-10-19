#include <gf/gf_scene.h>
#pragma force_active on

extern "C" void fn_1_10270(gfScene* scene) {
    extern const char lbl_1_data_4C88[];
    extern const char lbl_1_data_4C9C[];

    scene->setLoadModule(lbl_1_data_4C88, false);
    scene->setLoadModule(lbl_1_data_4C9C, false);
}
