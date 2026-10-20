#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    int unk8;
} fn_27_CA278_struct;

extern "C" int fn_27_CA278(fn_27_CA278_struct *p) {
    return p->unk8 >> 27;
}
