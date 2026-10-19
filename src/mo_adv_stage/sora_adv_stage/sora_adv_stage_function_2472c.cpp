#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_40_1E2F8(void* obj, int flags);

extern "C" {
void* fn_40_2472C(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_40_1E2F8, 0xa0, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
