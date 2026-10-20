#pragma force_active on
extern unsigned char lbl_27_data_3B8C0[0x90];

struct fn_27_1A60B8_Work {
    unsigned char* unk0;
    unsigned char* unk4;
    unsigned int unk8;
};

extern "C" {
void fn_27_1A60B8(fn_27_1A60B8_Work* p) {
    unsigned char* base = lbl_27_data_3B8C0;
    unsigned int flag = p->unk8;
    p->unk0 = base;
    p->unk4 = base + 0x48;
    p->unk8 = flag & 1;
}
}
