#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct bss_loc_t {
    u32 unk0;
    s32 unk4;
};

extern "C" {
extern bss_loc_t lbl_27_bss_7318;
extern bss_loc_t lbl_27_bss_7320;

void fn_27_2C2CF4(void) {
    lbl_27_bss_7318.unk0 = 0xFF;
    lbl_27_bss_7318.unk4 = 0;
    lbl_27_bss_7320.unk0 = 0xFF;
    lbl_27_bss_7320.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2C2CF4_ctor = (void*)fn_27_2C2CF4;
