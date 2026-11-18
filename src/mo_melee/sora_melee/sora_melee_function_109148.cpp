#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on
struct Flags6F { unsigned char top : 1; unsigned char rest : 7; };
struct Flags6C { unsigned char top : 2; unsigned char middle : 2; unsigned char rest : 4; };
struct Flags6E { unsigned char rest : 7; unsigned char low : 1; };

extern "C" {
extern s32 g_ftAudienceManager;
extern s32 lbl_27_bss_1B18;
extern void* lbl_27_bss_B8;
extern f32 lbl_27_data_4B84;
extern u8 lbl_27_data_91F78;
extern f32 lbl_27_rodata_F08;
void fn_27_10FBD0(s32, s32);
void* fn_27_4FAB4(void*);

void fn_27_109148(u8* p, s32 arg1) {
    void* mgr;
    switch (arg1) {
    case 0:
        lbl_27_bss_1B18 = 0;
        p[0x69] = 0;
        p[0x7C] = 1;
        p[0x6C] = (u8)((p[0x6C] | 0x80) & ~0x40);
        p[0x6E] = (u8)((p[0x6E] | 0x38) & ~0x02);
        ((struct Flags6F*) (p + 0x6F))->top = 0;
        lbl_27_data_91F78 = 1;
        break;
    case 1:
        lbl_27_bss_1B18 = 1;
        p[0x69] = 1;
        p[0x7C] = 0;
        p[0x6C] = (u8)(p[0x6C] | 0xC0);
        p[0x6E] = (u8)((p[0x6E] & ~0x38) | 0x02);
        p[0x6F] = (u8)(p[0x6F] | 0x80);
        lbl_27_data_91F78 = 0;
        break;
    }
    p[0x68] = (u8)arg1;
    ((Flags6C*)(p + 0x6C))->middle = 0;
    p[0x6F] = (u8)(p[0x6F] | 0x10);
    ((Flags6E*)(p + 0x6E))->low = 0;
    p[0x6E] &= ~0x04;
    p[0x6B] = 0;
    fn_27_10FBD0(g_ftAudienceManager, arg1);
    if (lbl_27_bss_B8 == 0) {
        mgr = operator new(0x1508, Heaps::System);
        if (mgr != 0) {
            mgr = fn_27_4FAB4(mgr);
        }
        lbl_27_bss_B8 = mgr;
    }
    lbl_27_data_4B84 = lbl_27_rodata_F08;
}
}
