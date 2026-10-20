#pragma force_active on
typedef void (*DtorFn)(void*, int);

extern "C" void __destroy_arr(void*, DtorFn, unsigned long, unsigned long);
extern "C" void* fn_27_84198(void* p, int n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1E4798(void* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (DtorFn)fn_27_84198, 0xC, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
