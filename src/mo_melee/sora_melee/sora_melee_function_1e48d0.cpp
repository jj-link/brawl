#pragma force_active on
extern "C" void* fn_27_84458(void* p, int n);
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void* (*)(void*, int), unsigned long, unsigned long);

extern "C" void* fn_27_1E48D0(void* arg1, int arg2) {
    if (arg1 != 0) {
        __destroy_arr((char*)arg1 + 0xc, (void* (*)(void*, int))fn_27_84458, 0xc, 0x7);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
