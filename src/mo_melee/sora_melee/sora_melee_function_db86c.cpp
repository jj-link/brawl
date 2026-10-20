#pragma force_active on
extern "C" {
typedef unsigned long u32_t;
void* fn_27_84458(void* p, int n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_DB86C(char* p, int flag) {
    if (p) {
        __destroy_arr(p + 0xC, (void (*)(void*, int))fn_27_84458, 0xC, 0x16);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
