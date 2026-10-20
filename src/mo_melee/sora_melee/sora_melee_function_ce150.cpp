#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_25290(void*, int);

extern "C" void* fn_27_CE150(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_25290, 0x30, 0x73);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
