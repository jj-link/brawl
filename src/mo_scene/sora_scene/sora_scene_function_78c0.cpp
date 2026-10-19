#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" const char lbl_1_data_1A10[0x58];

extern "C" void fn_1_78C0(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_1A10 + 0xC, false);
    scene->setLoadModule(lbl_1_data_1A10 + 0x20, false);
    scene->setLoadModule(lbl_1_data_1A10 + 0x40, false);
}
