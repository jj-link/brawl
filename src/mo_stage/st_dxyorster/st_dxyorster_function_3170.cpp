#pragma force_active on
extern "C" void* fn_76_3CA0(void* p, int n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_76_3170(char* p, int n) {
    if (p != 0) {
        __destroy_arr(p + 0xc, (void (*)(void*, int))fn_76_3CA0, 0xa0, 9);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
