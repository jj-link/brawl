#include <gf/gf_scene.h>
#pragma force_active on

extern "C" unsigned char lbl_1_data_2160[];

extern "C" void fn_1_9418(gfScene* scene) {
    scene->setLoadModule(reinterpret_cast<const char*>(lbl_1_data_2160 + 0x0C), false);
    scene->setLoadModule(reinterpret_cast<const char*>(lbl_1_data_2160 + 0x20), false);
    scene->setLoadModule(reinterpret_cast<const char*>(lbl_1_data_2160 + 0x34), false);
    scene->setLoadModule(reinterpret_cast<const char*>(lbl_1_data_2160 + 0x54), false);
}
