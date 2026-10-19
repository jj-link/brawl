#pragma force_active on
extern "C" void fn_27_1A0CAC(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_116_38F0(void* self, short flags) {
    if (self != 0) {
        fn_27_1A0CAC(self, (short)-1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
