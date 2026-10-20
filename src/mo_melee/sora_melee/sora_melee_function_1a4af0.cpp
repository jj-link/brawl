#pragma force_active on
struct Bits {
    unsigned int a : 7;
    unsigned int b : 7;
    unsigned int c : 18;
};

extern "C" void fn_27_1A4AF0(unsigned char* p, unsigned int v) {
    Bits* w = (Bits*)(p + 8);
    w->b = v;
}
