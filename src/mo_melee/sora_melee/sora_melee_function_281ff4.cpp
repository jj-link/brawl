#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_290F90(void*, int);
extern "C" void fn_27_AB18C(void*, int);

extern "C" void* fn_27_281FF4(void* a1, int a2) {
    if (a1) {
        __destroy_arr((char*)a1 + 0x38, fn_27_290F90, 0xcc, 1);
        if ((char*)a1 + 0x18) {
            __destroy_arr((char*)a1 + 0x24, fn_27_AB18C, 0x14, 1);
        }
        if (a2 > 0)
            __dl__FPv(a1);
    }
    return a1;
}
