#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

extern void *g_GameGlobal;

extern "C" {
void fn_8014FC64(u32 arg0, u8 arg1, u8 arg2) {
    char *p = *(char **)((char *)g_GameGlobal + 0x34);
    p[0x23] = (u8)(arg0 >> 8);
    p[0x24] = (u8)arg0;
    p[0x25] = arg1;
    p[0x26] = arg2;
}
}
