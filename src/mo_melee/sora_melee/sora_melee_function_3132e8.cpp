#pragma force_active on
extern "C" void* fn_27_97968(void*, short);
extern "C" void fn_27_9FA50(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3132E8(void* self, int deleteFlag) {
    if (self) {
        fn_27_97968((char*)self + 0x58, -1);
        if (self && self) {
            __destroy_arr((char*)self + 0xC, fn_27_9FA50, 0x2C, 1);
        }
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
