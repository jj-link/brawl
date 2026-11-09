#include <gr/gr_gimmick.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" {
extern const char lbl_77_data_1B70[];
extern const char lbl_77_data_1B78[];
}

struct DxGardenObject {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x108];
    unsigned char state;
    char pad151[7];
    unsigned char kind;
};

extern "C" void fn_77_6164(DxGardenObject* self, float deltaFrame) {
    reinterpret_cast<grGimmick*>(self)->grGimmick::update(deltaFrame);

    switch (self->state) {
    case 0:
        switch (self->kind) {
        case 0: {
            g_ecMgr->setDrawPrio(1);
            u32 effect = g_ecMgr->setEffect((EfID)0x5C0001);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setParent(effect, *self->model, lbl_77_data_1B70, false);
            break;
        }
        case 1: {
            g_ecMgr->setDrawPrio(1);
            u32 effect = g_ecMgr->setEffect((EfID)0x5C0002);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setParent(effect, *self->model, lbl_77_data_1B78, false);
            break;
        }
        }
        self->state = 1;
    case 1:
        break;
    }
}
