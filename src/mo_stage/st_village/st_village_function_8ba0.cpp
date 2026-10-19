#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_70_8B60(void* p, int n);
}

extern "C" void* fn_70_8BA0(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_70_8B60, 8, 6);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
