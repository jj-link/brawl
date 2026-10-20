#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern unsigned char lbl_27_data_3DD00[];
}

struct fn_27_1A517C_work {
    unsigned char *unk0;
    unsigned char *unk4;
    u32 unk8;
};

extern "C" void fn_27_1A517C(fn_27_1A517C_work *p) {
    u32 v = p->unk8;
    p->unk0 = lbl_27_data_3DD00;
    p->unk4 = lbl_27_data_3DD00 + 0x48;
    p->unk8 = v & 0x3FFFFF;
}
