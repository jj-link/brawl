#include <gf/gf_scene.h>
#pragma force_active on

extern "C" {
extern const char lbl_1_data_44[];

void fn_1_678(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_44, false);
}
}
