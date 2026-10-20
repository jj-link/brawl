#pragma force_active on
typedef unsigned int u32;

extern "C" {
    extern unsigned char lbl_27_data_3BDA8[];
}

struct FnWork {
    void *unk0;
    void *unk4;
    u32 unk8;
};

extern "C" void fn_27_1991F0(FnWork *p) {
    u32 v = p->unk8;
    p->unk0 = lbl_27_data_3BDA8;
    p->unk4 = lbl_27_data_3BDA8 + 0x48;
    p->unk8 = v & 0x1FFF;
}
