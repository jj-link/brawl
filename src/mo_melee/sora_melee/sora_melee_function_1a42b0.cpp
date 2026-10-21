#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 f : 10;
    u32 rest : 22;
};

extern "C" void fn_27_1A42B0(void* p, u32 v) {
    S* s = (S*)((char*)p + 8);
    s->f = v;
}
