#pragma force_active on
extern "C" {
void fn_18_CE0(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_18_68E0(void* p, int flag) {
    if (p) {
        if (p) {
            __destroy_arr((char*)p + 0x48, fn_18_CE0, 0xa8, 9);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
