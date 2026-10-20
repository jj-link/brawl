#pragma force_active on
extern "C" void fn_27_84458(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_1B22F8(void* self, int flags) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_84458, 0xc, 0x28);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
