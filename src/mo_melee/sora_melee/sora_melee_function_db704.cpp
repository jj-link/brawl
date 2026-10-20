#pragma force_active on
typedef void (*DtorFn)(void*, int);
extern "C" void* fn_27_84418(void* p, int n);
extern "C" void __destroy_arr(void* p, DtorFn dtor, unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_DB704(void* p, int doDelete) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (DtorFn)fn_27_84418, 0xc, 1);
        if (doDelete > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
