#include <types.h>
#pragma force_active on

struct lbl_27_bss_414_t {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkc;
};

extern lbl_27_bss_414_t lbl_27_bss_414;

extern "C" {
lbl_27_bss_414_t *fn_27_2DA26C(void) {
    return &lbl_27_bss_414;
}
}
