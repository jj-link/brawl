#pragma force_active on
extern "C" {
void fn_71_9564(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_71_F1AC(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_71_9564, 8, 7);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
