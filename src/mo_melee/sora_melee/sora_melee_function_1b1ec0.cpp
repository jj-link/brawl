#pragma force_active on
extern "C" {
void fn_27_84398(void* ptr, int size);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_1B1EC0(void* p, int del) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_84398, 0xC, 0xB);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
