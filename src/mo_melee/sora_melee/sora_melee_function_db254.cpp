#pragma force_active on
extern "C" {
void fn_27_842D8(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_DB254(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_842D8, 0xC, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
