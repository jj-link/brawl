#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern bss_loc_t lbl_27_bss_3138;
extern bss_loc_t lbl_27_bss_3140;

extern "C" {
void fn_27_13F1D8() {
    lbl_27_bss_3138.unk0 = 0xFF;
    lbl_27_bss_3138.unk4 = 0;
    lbl_27_bss_3140.unk0 = 0xFF;
    lbl_27_bss_3140.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_13F1D8_ctor = (void*)fn_27_13F1D8;
