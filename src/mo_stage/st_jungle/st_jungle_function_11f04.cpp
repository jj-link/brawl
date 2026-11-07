#include <ec/ec_mgr.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" {
extern const char lbl_51_data_81C8[];
extern const float lbl_51_rodata_1D0;
extern const float lbl_51_rodata_1D8;
}
struct Ground {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x108];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x3c];
    float x, y, z;
    snd3DGenerator sound;
};
extern "C" void fn_51_11F04(Ground* self) {
    switch (self->state) {
    case 1:
        g_ecMgr->setDrawPrio(1);
        u32 effect = g_ecMgr->setEffect((EfID)0x390003);
        g_ecMgr->setDrawPrio(-1);
        g_ecMgr->setParent(effect, *self->model, lbl_51_data_81C8, false);
        self->sound.playSE((SndID)0x1b90, 0, 0, -1);
        self->x = lbl_51_rodata_1D0;
        self->y = lbl_51_rodata_1D0;
        self->z = lbl_51_rodata_1D0;
        self->timer = lbl_51_rodata_1D8;
        self->state = 2;
        break;
    }
}