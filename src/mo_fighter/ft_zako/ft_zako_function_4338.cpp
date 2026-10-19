#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_4338(void* self, short flag) {
    if (self != 0) {
        fn_27_1540CC(self, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
