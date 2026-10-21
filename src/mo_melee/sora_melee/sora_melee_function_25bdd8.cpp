#pragma force_active on
typedef struct {
    unsigned int unk0;
    int unk4;
} bss_loc_t;

extern bss_loc_t lbl_27_bss_5A08;
extern bss_loc_t lbl_27_bss_5A10;

extern "C" void fn_27_25BDD8() {
    lbl_27_bss_5A08.unk0 = 0xFF;
    lbl_27_bss_5A08.unk4 = 0;
    lbl_27_bss_5A10.unk0 = 0xFF;
    lbl_27_bss_5A10.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_25BDD8_ctor = (void*)fn_27_25BDD8;
