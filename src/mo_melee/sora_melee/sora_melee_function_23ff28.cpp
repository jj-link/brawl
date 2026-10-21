#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern bss_loc_t lbl_27_bss_5930;
extern bss_loc_t lbl_27_bss_5938;

void fn_27_23FF28() {
    lbl_27_bss_5930.unk0 = 0xFF;
    lbl_27_bss_5930.unk4 = 0;
    lbl_27_bss_5938.unk0 = 0xFF;
    lbl_27_bss_5938.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_23FF28_ctor = (void*)fn_27_23FF28;
