#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" {

unsigned int lbl_1_data_1920[];

void fn_1_7780(gfScene* scene) {
    scene->setLoadModule((const char*)(lbl_1_data_1920 + 4), false);
    scene->setLoadModule((const char*)(lbl_1_data_1920 + 9), false);
    scene->setLoadModule((const char*)(lbl_1_data_1920 + 14), false);
    scene->setLoadModule((const char*)(lbl_1_data_1920 + 22), false);
    scene->setLoadModule((const char*)(lbl_1_data_1920 + 28), false);
}

}
