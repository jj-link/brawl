#include <types.h>
#pragma force_active on

struct acCmdInterpreterStackData {
    s32 m0;
    s32 m4;
    u8 m8;
    s32 mC;
    f32 m10;
};

template <class T>
struct soArrayNull {
    T& at(long idx);
};

extern "C" {
extern signed char lbl_27_bss_5050;
extern acCmdInterpreterStackData lbl_27_bss_5054;
extern const f32 lbl_27_rodata_2708;
}

template <>
acCmdInterpreterStackData& soArrayNull<acCmdInterpreterStackData>::at(long idx) {
    if (!lbl_27_bss_5050) {
        lbl_27_bss_5054.m0 = -1;
        lbl_27_bss_5054.m4 = 0;
        lbl_27_bss_5054.m8 = 0;
        lbl_27_bss_5054.mC = 0;
        lbl_27_bss_5054.m10 = lbl_27_rodata_2708;
        lbl_27_bss_5050 = 1;
    }
    return lbl_27_bss_5054;
}
