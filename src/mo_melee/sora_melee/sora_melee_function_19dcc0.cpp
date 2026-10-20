#pragma force_active on
typedef unsigned long u32;

extern "C" void fn_27_46700(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_19DCC0(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_46700, 0x60, 0xE);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
