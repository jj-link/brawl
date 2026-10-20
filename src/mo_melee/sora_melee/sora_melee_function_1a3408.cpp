#pragma force_active on
extern char lbl_27_data_36888[];

struct fn_27_1A3408_Work {
    char* unk0;
    char* unk4;
    unsigned int unk8;
};

extern "C" {
void fn_27_1A3408(fn_27_1A3408_Work* p) {
    unsigned int flag = p->unk8;
    char* base = lbl_27_data_36888;
    char* next = base + 0x48;
    p->unk0 = base;
    p->unk4 = next;
    p->unk8 = flag & 1;
}
}
