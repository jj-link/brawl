#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_84598(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_263E2C(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_84598, 0xC, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
