#include <types.h>
#pragma force_active on

struct lbl_27_bss_71DC_t {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern lbl_27_bss_71DC_t lbl_27_bss_71DC;

extern "C" lbl_27_bss_71DC_t* fn_27_2BF65C()
{
    return &lbl_27_bss_71DC;
}
