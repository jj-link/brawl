#pragma force_active on
extern "C" {
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct MenuEntry3 { u8 unk0; u8 unk1; u8 unk2; };

u32* fn_8004E580(void*);
extern void* g_GameGlobal;
extern MenuEntry3 lbl_80407A40[];

void setCharRefered__6muMenuFiii(s32 idx, s32 arg1, s32 arg2, s32 arg3) {
    u32* bits = fn_8004E580(g_GameGlobal);
    s32 ch = lbl_80407A40[idx].unk1;
    if (ch != 0xE) {
        s32 n = (ch * 3) + 2;
        s32 w = n / 32;
        bits[w] |= 1 << (n % 32);
    }
}
}
