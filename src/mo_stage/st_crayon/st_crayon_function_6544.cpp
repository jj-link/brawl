#pragma force_active on
struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};
struct S {
    char pad[8];
    Bits bits;
};
extern "C" void fn_56_6544(S* s, int v) {
    s->bits.b = v;
}
