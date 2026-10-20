#pragma force_active on
extern "C" {
typedef void (*DtorFn)(void*, int);

void* fn_27_84418(void*, int);
void __destroy_arr(void*, DtorFn, unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_1B27A8(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (DtorFn)fn_27_84418, 0xc, 4);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
