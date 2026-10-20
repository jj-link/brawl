#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int a : 6;
    unsigned int f : 3;
    unsigned int b : 23;
};

extern "C" {
void fn_27_19D6E0(Obj* p, unsigned int v) {
    p->f = v;
}
}
