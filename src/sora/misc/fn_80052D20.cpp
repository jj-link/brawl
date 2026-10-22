#pragma force_active on
typedef unsigned short u16;
typedef int s32;

extern "C" {
extern s32 fn_8005680C(u16);
extern s32 fn_80056864(s32);
extern s32 fn_800568A0(void);
extern void* g_GameGlobal;

s32 fn_80052D20(void) {
    s32 count = 0;
    s32 n = fn_800568A0();
    s32 i;
    for (i = 0; i < n; i++) {
        s32 r = fn_80056864(i);
        if (r >= 0) {
            s32 idx = fn_8005680C((u16)r);
            char* base = *(char**)((char*)g_GameGlobal + 0x24);
            if (*(u16*)(base + idx * 2 + 0xD58) & 0x8000) {
                count++;
            }
        }
    }
    return count;
}
}
