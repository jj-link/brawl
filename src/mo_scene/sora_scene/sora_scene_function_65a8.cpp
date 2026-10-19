#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_1480[];

extern "C" bool fn_1_65A8(gfScene* scene) {
    return scene->setLoadModule(lbl_1_data_1480, false);
}
