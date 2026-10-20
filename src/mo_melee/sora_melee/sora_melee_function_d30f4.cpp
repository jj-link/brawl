#pragma force_active on
struct Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int mode : 2;
};

extern "C" {
void fn_27_D30F4(Obj* p, unsigned int v) {
    p->mode = v;
}
}
