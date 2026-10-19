#pragma force_active on
extern "C" void fn_27_C96C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F208(void* self, int p2) {
    if (self != 0) {
        fn_27_C96C0(self, static_cast<short>(-1));
        if (static_cast<short>(p2) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
