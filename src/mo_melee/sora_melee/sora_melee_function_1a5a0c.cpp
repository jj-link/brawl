#pragma force_active on
struct Obj {
    unsigned char pad[8];
    unsigned int hi : 10;
    unsigned int rest : 22;
};

extern "C" {
void fn_27_1A5A0C(Obj* p, unsigned int v) {
    p->hi = v;
}
}
