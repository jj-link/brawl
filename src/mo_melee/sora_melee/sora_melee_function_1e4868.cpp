#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_84258(void*, int);
void* fn_27_1E4868(char* p, int n);
}

void* fn_27_1E4868(char* p, int n) {
    if (p) {
        __destroy_arr(p + 0xc, fn_27_84258, 0xc, 1);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}
