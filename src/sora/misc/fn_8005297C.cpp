#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern "C" {
extern s32 fn_80056898(void);
extern s32 fn_800567D8(s32);
extern s32 fn_80056780(u16);
extern void* g_GameGlobal;

s32 fn_8005297C(void) {
    s32 count = 0;
    s32 total = fn_80056898();
    for (s32 i = 0; i < total; i++) {
        s32 val = fn_800567D8(i);
        if (val >= 0) {
            s32 idx = fn_80056780((u16)val);
            u8* base = *(u8**)((u8*)g_GameGlobal + 0x24);
            u16 v = *(u16*)(base + idx * 2 + 0x842);
            if (v & 0x8000) {
                count++;
            }
        }
    }
    return count;
}
}
