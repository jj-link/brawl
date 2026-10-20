#pragma force_active on
typedef unsigned long u32;

struct Unk {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern "C" {
extern Unk lbl_27_bss_DAC;
}

extern "C" Unk* fn_27_38450C() {
    return &lbl_27_bss_DAC;
}
