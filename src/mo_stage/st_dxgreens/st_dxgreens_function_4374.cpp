#pragma force_active on
typedef int s32;

extern "C" void* fn_79_551C(void* p, s32 flags);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_79_4374(void* p, s32 flags) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_79_551C, 0xa0, 0x1e);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
