typedef unsigned char u8;
typedef int s32;

extern "C" void* g_GameGlobal;

#pragma force_active on
extern "C" u8 fn_8015B038(s32 unused, s32 arg1) {
    s32 temp_r0;

    temp_r0 = ((s32*)g_GameGlobal)[0x30 / 4];
    if (temp_r0 != 0) {
        return ((u8*)arg1 + temp_r0)[0x4914];
    }
    return 0;
}
