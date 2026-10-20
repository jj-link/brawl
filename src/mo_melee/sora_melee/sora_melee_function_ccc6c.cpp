#pragma force_active on
extern "C" {
void fn_27_4AD20(void* p, int n);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_CCC6C(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xc, fn_27_4AD20, 0x5c, 2);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
