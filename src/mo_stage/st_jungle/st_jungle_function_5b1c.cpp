#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_51_5ADC(void*, int);

extern "C" void* fn_51_5B1C(void* ptr, int count) {
    if (ptr != 0) {
        __destroy_arr((void*)((char*)ptr + 0xc), fn_51_5ADC, 8UL, 7UL);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
