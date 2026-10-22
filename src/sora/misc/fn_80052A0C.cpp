#pragma force_active on
extern "C" {

typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern s32 fn_80056898(void);
extern s32 fn_800567D8(s32);
extern s32 fn_80056780(u16);
extern s32 fn_800562A4(u16);
extern void* g_GameGlobal;

s32 fn_80052A0C(u32 arg0) {
    s32 count = fn_80056898();
    for (s32 i = 0; i < count; i++) {
        s32 val = fn_800567D8(i);
        if (val < 0) continue;
        if (arg0 != (u32)(u16)fn_800562A4((u16)val)) continue;
        s32 idx = fn_80056780((u16)val);
        u8* base = *(u8**)((u8*)g_GameGlobal + 0x24);
        u16 flag = *(u16*)(base + idx * 2 + 0x842);
        if (!(flag & 0x8000)) return 0;
    }
    return 1;
}

}
