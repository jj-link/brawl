#pragma force_active on
extern "C" {
void* fn_67_4AFC(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_67_4B3C(void* p, int n);
}

void* fn_67_4B3C(void* p, int n) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_67_4AFC, 8, 6);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
