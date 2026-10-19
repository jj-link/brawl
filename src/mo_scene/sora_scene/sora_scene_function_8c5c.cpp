#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_1FA0[];

extern "C" void fn_1_8C5C(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_1FA0 + 0xC, false);
    scene->setLoadModule(lbl_1_data_1FA0 + 0x20, false);
    scene->setLoadModule(lbl_1_data_1FA0 + 0x40, false);
}
