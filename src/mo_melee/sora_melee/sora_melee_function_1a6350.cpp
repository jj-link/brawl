#pragma force_active on
struct Fn27Bits {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 12;
};

extern "C" void fn_27_1A6350(void* p, unsigned int v) {
    Fn27Bits* w = (Fn27Bits*)((char*)p + 8);
    w->b = v;
}
