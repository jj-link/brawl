#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_40_data_14BD8[];
void fn_27_26C65C(void*, void*, void*, void*, void*);
void fn_27_26C78C(void*, void*, void*, void*, void*);

void fn_40_3AEC4(char* arg0, s32 arg1) {
    char* data = lbl_40_data_14BD8;
    if (arg1 == 0) {
        fn_27_26C65C(arg0, data + 0x1CC, data + 0x80, arg0 + 0x1C0, data + 0x1D0);
        fn_27_26C65C(arg0, data + 0x1D4, data + 0x88, arg0 + 0x1C4, data + 0x1D8);
        fn_27_26C78C(arg0, data + 0x1DC, data + 0x94, arg0 + 0x1C8, data + 0x1E0);
        fn_27_26C78C(arg0, data + 0x1E4, data + 0xA0, arg0 + 0x1CC, data + 0x1E8);
        fn_27_26C78C(arg0, data + 0x1EC, data + 0xB0, arg0 + 0x1D0, data + 0x1F0);
    }
    if (arg1 == 1) {
        fn_27_26C65C(arg0, data + 0x1F4, data + 0xC0, arg0 + 0x1D4, data + 0x1F8);
        fn_27_26C65C(arg0, data + 0x1FC, data + 0xC8, arg0 + 0x1D8, data + 0x200);
        fn_27_26C78C(arg0, data + 0x204, data + 0xD4, arg0 + 0x1DC, data + 0x208);
        fn_27_26C78C(arg0, data + 0x20C, data + 0xE4, arg0 + 0x1E0, data + 0x210);
        fn_27_26C78C(arg0, data + 0x214, data + 0xF4, arg0 + 0x1E4, data + 0x218);
    }
    if (arg1 == 2) {
        fn_27_26C65C(arg0, data + 0x21C, data + 0x104, arg0 + 0x1E8, data + 0x220);
        fn_27_26C65C(arg0, data + 0x224, data + 0x10C, arg0 + 0x1EC, data + 0x228);
        fn_27_26C78C(arg0, data + 0x22C, data + 0x118, arg0 + 0x1F0, data + 0x230);
        fn_27_26C78C(arg0, data + 0x234, data + 0x124, arg0 + 0x1F4, data + 0x238);
    }
    if (arg1 == 3) {
        fn_27_26C65C(arg0, data + 0x23C, data + 0x130, arg0 + 0x1F8, data + 0x240);
        fn_27_26C78C(arg0, data + 0x244, data + 0x13C, arg0 + 0x1FC, data + 0x248);
    }
}
}
