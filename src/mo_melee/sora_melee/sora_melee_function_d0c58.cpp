#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_25290(void* ptr, int count);

extern "C" void* fn_27_D0C58(void* self, int del) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_25290, 0x30, 0x36);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
