#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern void *g_GameGlobal;

extern "C" {
void fn_8014F868(u16 arg0, s8 arg1, s8 arg2) {
    u8 *temp_r6;

    temp_r6 = *(u8 **)((u8 *)g_GameGlobal + 0x34);
    temp_r6[0xB] = (u8)(arg0 >> 8);
    temp_r6[0xC] = (u8)arg0;
    temp_r6[0xD] = arg1;
    temp_r6[0xE] = arg2;
}
}
