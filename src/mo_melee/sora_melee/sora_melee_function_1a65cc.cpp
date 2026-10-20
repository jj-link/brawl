#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_34020[0x90];

struct fn_27_1A65CC_work {
    char* unk0;
    char* unk4;
    u32 unk8;
};

void fn_27_1A65CC(fn_27_1A65CC_work* p) {
    u32 v = p->unk8;
    char* t = lbl_27_data_34020;
    char* u = t + 0x48;
    p->unk0 = t;
    p->unk4 = u;
    p->unk8 = v & 1;
}
}
