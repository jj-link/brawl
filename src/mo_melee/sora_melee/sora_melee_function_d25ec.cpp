#pragma force_active on
struct fn_27_Struct {
    int unk0;
    int unk4;
    unsigned int flags : 2;
};

extern "C" {
void fn_27_D25EC(fn_27_Struct* p, unsigned int v) {
    p->flags = v;
}
}
