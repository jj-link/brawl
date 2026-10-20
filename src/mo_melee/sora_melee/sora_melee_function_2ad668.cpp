#pragma force_active on
typedef int s32;

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_2ADF54(void* p, s32 n);
}

extern "C" void* fn_27_2AD668(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_2ADF54, 0xC, 0x80);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
