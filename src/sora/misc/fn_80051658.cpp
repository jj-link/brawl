#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_8004E5C4(void* self);
extern "C" void* g_GameGlobal;

extern "C" u8 fn_80051658(void) {
    return ((u8*)fn_8004E5C4(g_GameGlobal))[0x2E5];
}
