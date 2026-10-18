#pragma force_active on
typedef int s32;

extern "C" void __dl__FPv(void*);

extern "C" void* fn_62_9A7C(void* p, s32 n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
