#pragma force_active on
struct Bits {
    unsigned int a : 4;
    unsigned int f : 4;
    unsigned int rest : 24;
};

extern "C" void fn_27_CBE54(void *p, unsigned int v) {
    ((struct Bits *)((char *)p + 8))->f = v;
}
