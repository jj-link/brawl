#include <types.h>
#pragma force_active on

struct Unknown10 {
    u32 mData[4];
};

extern "C" Unknown10 lbl_27_bss_DAC;

extern "C" Unknown10* fn_27_3844DC() {
    return &lbl_27_bss_DAC;
}
