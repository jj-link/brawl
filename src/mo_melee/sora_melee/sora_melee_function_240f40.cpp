#pragma force_active on
typedef struct BssPair {
    unsigned int unk0;
    int unk4;
} BssPair;

extern "C" {
extern BssPair lbl_27_bss_5950;
extern BssPair lbl_27_bss_5958;

void fn_27_240F40(void)
{
    lbl_27_bss_5950.unk0 = 0xFF;
    lbl_27_bss_5950.unk4 = 0;
    lbl_27_bss_5958.unk0 = 0xFF;
    lbl_27_bss_5958.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_240F40_ctor = (void*)fn_27_240F40;
