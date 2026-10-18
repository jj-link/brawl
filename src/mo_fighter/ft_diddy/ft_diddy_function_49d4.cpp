#pragma force_active on
extern "C" void fn_27_1A4264(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_49D4(void* self, int count) {
    if (self != 0) {
        fn_27_1A4264(self, (short)-1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
