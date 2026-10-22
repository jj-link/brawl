#pragma force_active on
typedef unsigned int u32;
typedef signed char s8;
typedef int s32;

struct Obj {
    char pad0[8];
    u32 unk8;
    s32 unkC;
};

extern void* g_GameGlobal;
extern "C" float getGameFrame__10GameGlobalCFv(void* self);
extern "C" void* fn_8014FE34();

extern "C" void fn_80158A5C(Obj* arg0) {
    u32 frame = (u32)getGameFrame__10GameGlobalCFv(g_GameGlobal);
    if ((u32)(arg0->unk8 + 0x10000) == 0xFFFF) {
        arg0->unk8 = frame;
        return;
    }
    char* p = (char*)fn_8014FE34();
    u32 d = frame - arg0->unk8;
    if (d <= 0x258) {
        arg0->unkC = arg0->unkC + (s8)p[0x39];
    } else if (d <= 0x384) {
        arg0->unkC = arg0->unkC + (s8)p[0x3A];
    } else if (d <= 0x4B0) {
        arg0->unkC = arg0->unkC + (s8)p[0x3B];
    } else if (d <= 0x5DC) {
        arg0->unkC = arg0->unkC + (s8)p[0x3C];
    } else if (d <= 0x708) {
        arg0->unkC = arg0->unkC + (s8)p[0x3D];
    } else if (d <= 0x834) {
        arg0->unkC = arg0->unkC + (s8)p[0x3E];
    } else if (d <= 0x960) {
        arg0->unkC = arg0->unkC + (s8)p[0x3F];
    } else {
        arg0->unkC = arg0->unkC + (s8)p[0x40];
    }
    arg0->unk8 = frame;
}
