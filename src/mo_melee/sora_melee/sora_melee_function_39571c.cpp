#pragma force_active on
typedef unsigned long u32;
typedef long s32;

extern "C" {
void __dl__FPv(void*);

void* fn_27_39571C(void* p, s32 n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
