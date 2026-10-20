#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_36980[];

struct Fn27Work {
    char* unk0;
    char* unk4;
    u32 unk8;
};

void fn_27_1A3304(Fn27Work* p) {
    p->unk0 = lbl_27_data_36980;
    p->unk4 = lbl_27_data_36980 + 0x48;
    p->unk8 = p->unk8 & 1;
}
}
