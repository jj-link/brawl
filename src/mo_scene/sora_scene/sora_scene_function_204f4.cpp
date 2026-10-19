#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_1_data_6528[];
extern const char lbl_1_data_6544[];

void fn_1_204F4(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_6528, false);
    scene->setLoadModule(lbl_1_data_6544, false);
}
}
