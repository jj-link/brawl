#include <gf/gf_application.h>
#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct UnkParam {
    union {
        bool asBool;
        u32 asInt;
    } unk0;
    u32 unk4;
};

struct FnParam {
    s32 unk0;
    s32 unk4;
    void* unk8;
};

extern "C" s32 fn_26_0(FnParam*, s32, s32, s32);
extern "C" void playBGM__9sndSystemFiUlb(void* self, u32 id, u32 param, u32 flag);
extern void* g_sndSystem;

struct scSceneFn {
    u8 pad0[0x8];
    s32 unk8;
    u32 unkC;
    u8 pad10[0x10];
};

extern "C" {
void fn_1_10338(scSceneFn* self) {
    UnkParam stack18;
    UnkParam stack10;
    UnkParam stack8;
    FnParam param;
    void* tmp;

    if (g_GameGlobal->m_advData) {
        stack10.unk0.asInt = g_GameGlobal->m_advData->m_record.unk4928;
        stack10.unk4 = g_GameGlobal->m_advData->m_record.unk492C;
    } else {
        stack18.unk0.asBool = false;
        stack18.unk4 = -1;
        stack10 = stack18;
    }
    tmp = (u8*)self + 0x10;
    stack8 = stack10;
    param.unk0 = stack8.unk4;
    param.unk4 = self->unkC;
    param.unk8 = tmp;
    self->unk8 = fn_26_0(&param, param.unk4, stack8.unk4, stack8.unk0.asInt);
    g_gfApplication->unkD0.endKeepScreen();
    playBGM__9sndSystemFiUlb(g_sndSystem, 0x270E, 0, 1);
}
}
