#pragma force_active on
struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};
struct Obj {
    char pad[8];
    Bits bits;
};
extern "C" void fn_56_65DC(Obj* o, unsigned int v) {
    o->bits.b = v;
}
