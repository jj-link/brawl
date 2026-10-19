#include <ec/ec_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" {
struct fn_27_9FBD8_Work {
    s32 unk0;
    u32 unk4;
    u32 unk8;
};

void fn_27_9FBD8(fn_27_9FBD8_Work* work) {
    g_ecMgr->endEffect(work->unk8);
    work->unk8 = 0;
    work->unk4 = 0;
    work->unk0 = -1;
}
}
