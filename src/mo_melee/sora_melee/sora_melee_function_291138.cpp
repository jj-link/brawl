#pragma force_active on
extern "C" {
void fn_27_70454(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_291138(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_70454, 4, 16);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}
}
