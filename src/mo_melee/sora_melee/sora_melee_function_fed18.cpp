#pragma force_active on
struct Fn27Bits {
    unsigned int a : 6;
    unsigned int f : 6;
    unsigned int b : 20;
};

extern "C" void fn_27_FED18(void* p, unsigned int v) {
    Fn27Bits* w = (Fn27Bits*)((char*)p + 8);
    w->f = v;
}
