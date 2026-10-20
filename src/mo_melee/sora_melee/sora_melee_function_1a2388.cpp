#pragma force_active on
struct Obj {
    unsigned char pad[8];
    unsigned int hi : 4;
    unsigned int lo : 28;
};

extern "C" void fn_27_1A2388(Obj* p, unsigned int v) {
    p->hi = v;
}
