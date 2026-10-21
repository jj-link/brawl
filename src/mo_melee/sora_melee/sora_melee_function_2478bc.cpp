#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    s32 unk4;
} bss_loc_t;

extern "C" {
extern bss_loc_t lbl_27_bss_5980;
extern bss_loc_t lbl_27_bss_5988;

void fn_27_2478BC() {
    lbl_27_bss_5980.unk0 = 0xFF;
    lbl_27_bss_5980.unk4 = 0;
    lbl_27_bss_5988.unk0 = 0xFF;
    lbl_27_bss_5988.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2478BC_ctor = (void*)fn_27_2478BC;
