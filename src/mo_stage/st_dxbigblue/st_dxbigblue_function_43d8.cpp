#include <st_dxbigblue/gr_dxbigblue.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);
void __dt__11grDxBigBlueFv(grDxBigBlue* ths, s32 flag);
}

extern "C" grDxBigBlue* fn_81_43D8(grDxBigBlue* ths, s32 flag) {
    if (ths != 0) {
        __dt__11grDxBigBlueFv(ths, 0);
        if (flag > 0) {
            __dl__FPv(ths);
        }
    }
    return ths;
}
