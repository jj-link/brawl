#pragma force_active on
typedef unsigned int u32;

struct bss_DAC_t {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern bss_DAC_t lbl_27_bss_DAC;

extern "C" bss_DAC_t *fn_27_384518()
{
    return &lbl_27_bss_DAC;
}
