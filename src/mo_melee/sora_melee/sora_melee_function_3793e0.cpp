#pragma force_active on
typedef unsigned long u32;

extern "C" void* fn_27_97968(void*, short);
extern "C" void fn_27_9FB88(void*, int);
extern "C" void fn_27_9FA50(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3793E0(void* self, int flags) {
    if (self != 0) {
        fn_27_97968((char*)self + 0x6C, -1);
        if ((char*)self + 0x38 && (char*)self + 0x38) {
            __destroy_arr((char*)self + 0x44, fn_27_9FB88, 0xC, 1);
        }
        if (self && self) {
            __destroy_arr((char*)self + 0xC, fn_27_9FA50, 0x2C, 1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
