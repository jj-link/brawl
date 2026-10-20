#pragma force_active on
struct Obj {
    unsigned char pad[8];
    unsigned int f : 4;
};

extern "C" {
void fn_27_19F6D0(Obj *p, unsigned int v) {
    p->f = v;
}
}
