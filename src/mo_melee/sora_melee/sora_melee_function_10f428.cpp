#pragma force_active on
struct BssPair {
    unsigned int unk0;
    int unk4;
};

extern "C" BssPair lbl_27_bss_2E58;
extern "C" BssPair lbl_27_bss_2E60;

extern "C" {
void fn_27_10F428()
{
    lbl_27_bss_2E58.unk0 = 0xFF;
    lbl_27_bss_2E58.unk4 = 0;
    lbl_27_bss_2E60.unk0 = 0xFF;
    lbl_27_bss_2E60.unk4 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_10F428_ctor = (void*)fn_27_10F428;
