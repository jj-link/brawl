#pragma force_active on
extern "C" {
extern void *g_GameGlobal;

typedef unsigned char u8;
typedef unsigned short u16;

u16 fn_8014FE44(void) {
    u8 *temp_r3;
    temp_r3 = *(u8 **)((u8 *)g_GameGlobal + 0x34);
    return (u16)(temp_r3[0x85] + (temp_r3[0x84] << 8));
}
}
