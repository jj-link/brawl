#pragma force_active on
extern "C" {
void* fn_27_86D8C(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_19C818(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_86D8C, 0x14, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
