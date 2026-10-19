#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_154874(void* p, s32 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
