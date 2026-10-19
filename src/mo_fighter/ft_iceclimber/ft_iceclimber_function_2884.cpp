#pragma force_active on
typedef signed short s16;

extern "C" void fn_27_1A61E0(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_105_2884(void* self, s16 flags) {
    if (self != 0) {
        fn_27_1A61E0(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
