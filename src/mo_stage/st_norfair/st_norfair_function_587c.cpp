#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_54_6388(void* p, int n);
}

extern "C" void* fn_54_587C(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, fn_54_6388, 0xa0, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
