#pragma force_active on
extern "C" {
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_2_2AE30(void* p, int n) {
    if (p) {
        if (p) {
            if (p) {
                if (p) {
                    __destroy_arr((char*)p + 0x48, fn_2_37C, 0xA8, 9);
                }
            }
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
