#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int unk8;
} FnObj;

extern "C" {
void fn_27_2648F4(FnObj* p) {
    p->unk8 &= 0xFDFFFFFF;
}
}
