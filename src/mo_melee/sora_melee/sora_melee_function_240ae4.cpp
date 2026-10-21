#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct BssPair {
    u32 unk0;
    s32 unk4;
};

extern BssPair lbl_27_bss_5940;
extern BssPair lbl_27_bss_5948;

extern "C" void fn_27_240AE4(void)
{
    lbl_27_bss_5940.unk0 = 0xFF;
    lbl_27_bss_5940.unk4 = 0;
    lbl_27_bss_5948.unk0 = 0xFF;
    lbl_27_bss_5948.unk4 = 1;
}

__declspec(section ".ctors") extern void* const fn_27_240AE4_ctor = (void*)fn_27_240AE4;
