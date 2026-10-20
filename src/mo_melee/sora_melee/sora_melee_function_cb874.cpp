#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int a : 3;
    unsigned int b : 29;
};

extern "C" {
void fn_27_CB874(struct Obj *p, unsigned int v) {
    p->a = v;
}
}
