#pragma force_active on
extern "C" {
void* fn_27_7D898(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_C9A14(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC,
                      (void (*)(void*, int))fn_27_7D898, 0x1C, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
