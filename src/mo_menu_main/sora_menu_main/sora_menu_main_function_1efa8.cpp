#pragma force_active on
extern "C" void fn_2_37C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_2_1EFA8(void* self, int flags) {
    if (self) {
        if (self) {
            __destroy_arr((char*)self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
