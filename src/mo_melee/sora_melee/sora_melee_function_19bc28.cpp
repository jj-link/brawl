#pragma force_active on
struct S {
    unsigned int a : 5;
    unsigned int f : 5;
    unsigned int b : 22;
};

extern "C" void fn_27_19BC28(void* p, unsigned int v) {
    S* s = (S*)((char*)p + 8);
    s->f = v;
}
