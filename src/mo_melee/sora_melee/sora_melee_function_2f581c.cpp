#pragma force_active on
typedef unsigned long u32;

extern "C" void* fn_27_13C90(void*, short);
extern "C" void fn_27_137EC(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2F581C(void* self, int flags) {
    if (self != 0) {
        fn_27_13C90((char*)self + 0x54, -1);
        if ((char*)self + 4 && (char*)self + 4) {
            __destroy_arr((char*)self + 0x10, fn_27_137EC, 0x2c, 1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
