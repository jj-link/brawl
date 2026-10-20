#pragma force_active on
extern "C" void fn_27_1D08E4(void* p, unsigned int v) {
    struct Bits {
        unsigned int a : 4;
        unsigned int b : 4;
        unsigned int c : 24;
    };
    ((Bits*)((char*)p + 8))->b = v;
}
