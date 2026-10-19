#pragma force_active on
typedef signed short s16;

extern "C" void fn_122_12BB4(void* self, s16 arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_122_12C2C(void* self, s16 flag) {
    if (self != 0) {
        fn_122_12BB4(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
