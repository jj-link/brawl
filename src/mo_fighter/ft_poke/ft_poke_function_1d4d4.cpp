#pragma force_active on
extern "C" void fn_116_1D530(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_1D4D4(void* self, short flag) {
    if (self != 0) {
        fn_116_1D530(self, (short)-1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
