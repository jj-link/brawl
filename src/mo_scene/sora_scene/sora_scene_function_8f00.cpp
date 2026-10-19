#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_20CC[];
extern "C" char lbl_1_data_20E0[];

extern "C" void fn_1_8F00(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_20CC, false);
    scene->setLoadModule(lbl_1_data_20E0, false);
}
