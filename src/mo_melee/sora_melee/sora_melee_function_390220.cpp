#pragma force_active on
struct fn_27_390220_obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int mode : 3;
    unsigned int rest : 29;
};

extern "C" {
void fn_27_390220(fn_27_390220_obj* p, unsigned int v) {
    p->mode = v;
}
}
