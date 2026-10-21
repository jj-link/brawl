#include <types.h>
#pragma force_active on

extern "C" void fn_800E5174(void*, u32);
extern s32 g_IfAdvMngr;
extern f32 lbl_27_rodata_41A0;

extern "C" void fn_27_25B458(u8* base, u32 index, u32 value) {
    if (value == 0) {
        u8* entry = base + index;
        if (value != entry[0x6B] && entry[0x64] == 0) {
            if (g_IfAdvMngr != 0) {
                u8* managerEntry = (u8*)g_IfAdvMngr + index * 4;
                void* nested = *(void**)(managerEntry + 0xE8);
                if (*(s32*)((u8*)nested + 0x354) != 0) {
                    fn_800E5174(nested, 0);
                }
            }

            *(f32*)(base + index * 4 + 0x98) = lbl_27_rodata_41A0;
        }
    }

    (base + index)[0x6B] = (u8)value;
}
