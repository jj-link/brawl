#pragma force_active on
extern "C" void fn_27_19C818(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_A5A8(void* self, short flag) {
    if (self != 0) {
        fn_27_19C818(self, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
