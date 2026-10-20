#pragma force_active on
extern "C" void fn_27_B21D0(void*, short);
extern "C" void fn_27_B164C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_379C2C(void* self, int doDelete) {
    if (self) {
        fn_27_B21D0((char*)self + 0x50, -1);
        if (self && self) {
            __destroy_arr((char*)self + 0xc, fn_27_B164C, 0x44, 1);
        }
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
