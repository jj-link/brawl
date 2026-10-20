#pragma force_active on
extern "C" {
void fn_27_AB18C(void*, short);
void __destroy_arr(void*, void (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_CD934(char* p, int del) {
    if (p) {
        __destroy_arr(p + 0xC, fn_27_AB18C, 0x14, 1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
