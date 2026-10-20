#pragma force_active on
extern "C" void fn_27_1A3C4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_454C(void* self, short flag) {
    if (self != 0) {
        fn_27_1A3C4C(self, (short)-1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
