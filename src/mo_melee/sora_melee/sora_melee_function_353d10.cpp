#pragma force_active on
extern "C" void fn_27_31F178(void* p, int arg);
extern "C" void fn_27_352B04(void* self, int v);
extern "C" void* fn_27_1D81C8(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_353D10(void* self, int flags) {
    if (self) {
        if (self) {
            if ((unsigned int)self + 0xcc) {
                fn_27_31F178((char*)self + 0x17a4, -1);
                fn_27_352B04((char*)self + 0xcc, 0);
            }
            fn_27_1D81C8(self, 0);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
