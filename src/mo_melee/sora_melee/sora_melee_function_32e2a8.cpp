#pragma force_active on
typedef int s32;

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_32E2A8(void* p, s32 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
