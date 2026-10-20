#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_25290();

extern "C" void* fn_27_19FFEC(char* self, int del) {
    if (self) {
        __destroy_arr(self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
