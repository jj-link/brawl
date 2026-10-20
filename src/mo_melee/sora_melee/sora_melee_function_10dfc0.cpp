#pragma force_active on
typedef unsigned long u32;
typedef long s32;

extern "C" void* fn_27_10E04C(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), u32 elemSize, u32 count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_10DFC0(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_10E04C, 0xc, 8);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
