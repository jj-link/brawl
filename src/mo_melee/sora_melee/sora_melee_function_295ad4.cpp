#pragma force_active on
struct Fn27Bits {
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
};

extern "C" void fn_27_295AD4(void *obj, unsigned int v) {
    Fn27Bits *s = (Fn27Bits *)((char *)obj + 8);
    s->b = v;
}
