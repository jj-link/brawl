#pragma force_active on
extern "C" void fn_27_84458(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1B1CE0(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_84458, 0xc, 0x14);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
