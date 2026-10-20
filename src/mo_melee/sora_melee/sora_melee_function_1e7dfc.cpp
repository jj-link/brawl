#pragma force_active on
struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_27_1E7DFC(Bits* p, unsigned int v) {
    p[2].b = v;
}
