#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int hi : 10;
    unsigned int f : 10;
    unsigned int lo : 12;
};

extern "C" {
void fn_27_1A41CC(Obj* p, unsigned int v) {
    p->f = v;
}
}
