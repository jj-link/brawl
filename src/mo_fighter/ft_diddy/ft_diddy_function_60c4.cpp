#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_60C4(void* self, int p2) {
    if (self) {
        fn_27_1A75E4(self, static_cast<short>(-1));
        if (static_cast<short>(p2) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
