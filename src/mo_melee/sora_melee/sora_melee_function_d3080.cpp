#pragma force_active on
typedef int s32;

extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_27_86D4C(void* p, int n);

extern "C" void* fn_27_D3080(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_86D4C, 0xA0, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
