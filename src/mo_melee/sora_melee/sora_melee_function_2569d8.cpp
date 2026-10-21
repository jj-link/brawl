#pragma force_active on
struct bss_loc {
    unsigned int unk0;
    int unk4;
};

extern bss_loc lbl_27_bss_59C8;
extern bss_loc lbl_27_bss_59D0;

extern "C" {
void fn_27_2569D8() {
    lbl_27_bss_59C8.unk0 = 0xFF;
    lbl_27_bss_59C8.unk4 = 0;
    lbl_27_bss_59D0.unk0 = 0xFF;
    lbl_27_bss_59D0.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2569D8_ctor = (void*)fn_27_2569D8;
