#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_801BF470(void*, int);
}

extern "C" void* fn_801C5DAC(char* object, int flags) {
    if (object != 0) {
        __destroy_arr(object + 8, fn_801BF470, 0x14, 8);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
