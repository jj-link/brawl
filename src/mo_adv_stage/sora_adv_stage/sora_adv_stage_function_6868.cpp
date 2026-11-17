#include <types.h>
#include <ft/ft_manager.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void fn_40_B48(const char*, ...);
void fn_27_109294(void* self, s32 val);
void fn_27_1092D0(void* self, u8 value);
void fn_27_1F1844(u8 value);
extern char lbl_40_data_0[];
extern const float lbl_40_rodata_80;
extern const float lbl_40_rodata_90;
}

extern "C" void fn_40_6868(void* self) {
    char* base = lbl_40_data_0;
    unsigned char* s = (unsigned char*)self;
    unsigned char* vec = (unsigned char*)(*(u32*)((unsigned char*)g_GameGlobal + 8));
    u8 state = *(u8*)(*(unsigned char**)(s + 0x524) + 0x604);

    switch (state) {
    case 0: {
        fn_40_B48(base + 0x658);
        fn_27_109294(g_ftManager, 1);
        ((unsigned char*)g_ftManager)[0x6f] |= 0x80;
        fn_27_1092D0(g_ftManager, 0);
        for (int i = 0; i < 7; i++) {
            *(float*)(vec + 0xdc) = lbl_40_rodata_90;
            u32 v = *(u32*)(s + 0x528);
            if (v - 0x5b010000 == 0x100 || v - 0x63000000 == 0x400) {
                *(float*)(vec + 0xdc) = lbl_40_rodata_80;
            }
            vec += 0x5c;
        }
        return;
    }
    case 1: {
        fn_40_B48(base + 0x670);
        fn_27_109294(g_ftManager, 0);
        ((unsigned char*)g_ftManager)[0x6f] |= 0x80;
        fn_27_1092D0(g_ftManager, 0);
        float f = lbl_40_rodata_90;
        *(float*)(vec + 0xdc) = f;
        *(float*)(vec + 0x138) = f;
        *(float*)(vec + 0x194) = f;
        *(float*)(vec + 0x1f0) = f;
        *(float*)(vec + 0x24c) = f;
        *(float*)(vec + 0x2a8) = f;
        *(float*)(vec + 0x304) = f;
        return;
    }
    case 2: {
        fn_40_B48(base + 0x688);
        fn_27_109294(g_ftManager, 0);
        fn_27_1092D0(g_ftManager, 0);
        fn_27_1F1844(0);
        u32 v = *(u32*)(s + 0x528);
        if (v - 0x5a000000 == 0x100 || v - 0x5a010000 == 0x100 || v - 0x5a020000 == 0x100) {
            ((signed char*)g_ftManager)[0x6f] &= 0xFFFFFF7F;
            float f = lbl_40_rodata_80;
            *(float*)(vec + 0xdc) = f;
            *(float*)(vec + 0x138) = f;
            *(float*)(vec + 0x194) = f;
            *(float*)(vec + 0x1f0) = f;
            *(float*)(vec + 0x24c) = f;
            *(float*)(vec + 0x2a8) = f;
            *(float*)(vec + 0x304) = f;
            return;
        }
        ((unsigned char*)g_ftManager)[0x6f] |= 0x80;
        float f = lbl_40_rodata_90;
        *(float*)(vec + 0xdc) = f;
        *(float*)(vec + 0x138) = f;
        *(float*)(vec + 0x194) = f;
        *(float*)(vec + 0x1f0) = f;
        *(float*)(vec + 0x24c) = f;
        *(float*)(vec + 0x2a8) = f;
        *(float*)(vec + 0x304) = f;
        return;
    }
    case 3: {
        fn_40_B48(base + 0x6a0);
        *(unsigned char*)(*(unsigned char**)(s + 0x524) + 0x607) |= 0x20;
        *(unsigned char*)(*(unsigned char**)(s + 0x524) + 0x607) |= 0x10;
        fn_27_109294(g_ftManager, 0);
        ((signed char*)g_ftManager)[0x6f] &= 0xFFFFFF7F;
        fn_27_1092D0(g_ftManager, 1);
        fn_27_1F1844(0);
        float f = lbl_40_rodata_80;
        *(float*)(vec + 0xdc) = f;
        *(float*)(vec + 0x138) = f;
        *(float*)(vec + 0x194) = f;
        *(float*)(vec + 0x1f0) = f;
        *(float*)(vec + 0x24c) = f;
        *(float*)(vec + 0x2a8) = f;
        *(float*)(vec + 0x304) = f;
        return;
    }
    case 4: {
        fn_40_B48(base + 0x6bc);
        float f = lbl_40_rodata_90;
        *(float*)(vec + 0xdc) = f;
        *(float*)(vec + 0x138) = f;
        *(float*)(vec + 0x194) = f;
        *(float*)(vec + 0x1f0) = f;
        *(float*)(vec + 0x24c) = f;
        *(float*)(vec + 0x2a8) = f;
        *(float*)(vec + 0x304) = f;
        return;
    }
    default:
        break;
    }
}
