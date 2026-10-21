#pragma force_active on
struct S {
    unsigned int pad : 15;
    unsigned int bit : 1;
};

extern "C" int fn_27_C6FB0(void *obj) {
    return ((S *)((char *)obj + 8))->bit;
}
