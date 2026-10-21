#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern bss_loc_t lbl_27_bss_71E8;
extern bss_loc_t lbl_27_bss_71F0;

extern "C" {
void fn_27_2C29D0() {
    lbl_27_bss_71E8.unk0 = 0xFF;
    lbl_27_bss_71E8.unk4 = 0;
    lbl_27_bss_71F0.unk0 = 0xFF;
    lbl_27_bss_71F0.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2C29D0_ctor = (void*)fn_27_2C29D0;
