#pragma force_active on
extern "C" {
typedef void* (*PFN_destroy)(void*, int);
void* fn_27_37D3C(void* p, int n);
void __destroy_arr(void* p, PFN_destroy dtor, unsigned long elemSize, unsigned long count);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_199724(void* p, int flag) {
    if (p) {
        __destroy_arr((unsigned char*)p + 0x0c, fn_27_37D3C, 0x78, 4);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
