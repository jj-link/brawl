#pragma force_active on
struct Bits {
    unsigned int a : 8;
    unsigned int f : 4;
    unsigned int b : 20;
};

extern "C" void fn_27_1A240C(void* p, unsigned int v) {
    struct Bits* s = (struct Bits*)((char*)p + 8);
    s->f = v;
}
