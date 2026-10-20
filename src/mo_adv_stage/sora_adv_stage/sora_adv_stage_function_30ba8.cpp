#pragma force_active on
extern "C" void fn_40_30BA8(void* p, unsigned int v) {
    struct Bits {
        unsigned int a : 10;
        unsigned int b : 5;
        unsigned int c : 17;
    };
    Bits* f = (Bits*)((char*)p + 8);
    f->b = v;
}
