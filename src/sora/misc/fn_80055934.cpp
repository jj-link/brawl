#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void *fn_8004E5C4(void *);
extern "C" void *g_GameGlobal;

extern "C" void fn_80055934(u32 arg0) {
    u8 *p = (u8 *)fn_8004E5C4(g_GameGlobal);
    int overflow;
    u8 value = p[0x32A];
    overflow = 0;
    if (arg0 > 0xFFU || value > 0xFFU - arg0) {
        overflow = 1;
    }
    u32 result = 0xFF;
    if (overflow == 0) {
        result = value + arg0;
    }
    p[0x32A] = result;
}
