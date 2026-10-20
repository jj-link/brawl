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
    T& at(long idx) const;
};

extern "C" {
extern signed char lbl_27_bss_5068;
extern acCmdInterpreterStackData lbl_27_bss_506C;
extern const f32 lbl_27_rodata_2708;
}

template <>
acCmdInterpreterStackData& soArrayNull<acCmdInterpreterStackData>::at(long idx) const {
    if (!lbl_27_bss_5068) {
        lbl_27_bss_506C.m0 = -1;
        lbl_27_bss_506C.m4 = 0;
        lbl_27_bss_506C.m8 = 0;
        lbl_27_bss_506C.mC = 0;
        lbl_27_bss_506C.m10 = lbl_27_rodata_2708;
        lbl_27_bss_5068 = 1;
    }
    return lbl_27_bss_506C;
}
