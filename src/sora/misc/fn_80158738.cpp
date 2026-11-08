#pragma force_active on
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;

struct Data {
    u32 unk0;
    int unk4;
    char pad[8];
    int unk10;
    u32 ids[4];
    u32 values[4];
};

extern void* g_GameGlobal;
extern "C" float getGameFrame__10GameGlobalCFv(void* self);
extern "C" void* fn_8014FE34();

extern "C" void fn_80158738(Data* arg0, int arg1, int arg2) {
    u32 frame = (u32)getGameFrame__10GameGlobalCFv(g_GameGlobal);
    if ((u32)(arg0->unk0 + 0x10000) == 0xFFFF) {
        arg0->unk0 = frame;
        return;
    }
    char* p = (char*)fn_8014FE34();
    u32 d = frame - arg0->unk0;
    if (d <= 0x3C) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x30];
    } else if (d <= 0x78) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x31];
    } else if (d <= 0xB4) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x32];
    } else if (d <= 0xF0) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x33];
    } else if (d <= 0x12C) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x34];
    } else if (d <= 0x1E0) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x35];
    } else if (d <= 0x258) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x36];
    } else if (d <= 0x2D0) {
        arg0->unk4 = arg0->unk4 + (s8)p[0x37];
    } else {
        arg0->unk4 = arg0->unk4 + (s8)p[0x38];
    }
    arg0->unk0 = frame;
    if (arg1 >= 0 && arg1 < 4) {
        if ((u32)(arg0->ids[arg1] + 0x10000) == 0xFFFF) {
            arg0->ids[arg1] = frame;
        } else if (frame / 600 != arg0->ids[arg1] / 600) {
            if (arg0->values[arg1] >= (u8)p[0x47]) {
                arg0->unk10 = arg0->unk10 + (s8)p[0x46];
            }
            arg0->ids[arg1] = frame;
            arg0->values[arg1] = 0;
        }
        arg0->values[arg1] = arg0->values[arg1] + arg2;
    }
}
