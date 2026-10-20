#pragma force_active on
struct Obj {
    unsigned char pad[8];
    unsigned int a : 9;
    unsigned int b : 9;
    unsigned int c : 14;
};

extern "C" {
void fn_27_5430C(Obj* p, unsigned int v) {
    p->b = v;
}
}
