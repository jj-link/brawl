#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_25EBB8(void* p, int n);
}

extern "C" void* fn_27_25EA2C(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 8, (void (*)(void*, int))fn_27_25EBB8, 0xC, 0x20);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
