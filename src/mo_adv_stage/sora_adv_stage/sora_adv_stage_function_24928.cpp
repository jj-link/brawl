#pragma force_active on
extern "C" {
struct Bits {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};
struct Outer {
    unsigned int w0;
    unsigned int w1;
    Bits w2;
};
void fn_40_24928(Outer* o, unsigned int v) {
    o->w2.b = v;
}
}
