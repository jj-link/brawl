#pragma force_active on
typedef unsigned long u32;

extern "C" void fn_27_137EC(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_C9858(void* self, int shouldDelete) {
    if (self) {
        __destroy_arr((char*)self + 0xc, fn_27_137EC, 0x2c, 3);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
