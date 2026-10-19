#pragma force_active on
extern "C" void fn_48_1F8C(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_48_C3A4(void* self, int del) {
    if (self) {
        fn_48_1F8C(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
