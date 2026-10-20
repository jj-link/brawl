#pragma force_active on
typedef signed short s16;

extern "C" {
void fn_93_1BB4(void* self, s16 arg);
void __dl__FPv(void* p);

void* fn_93_1D2C(void* self, s16 flag) {
    if (self != 0) {
        s16 zero = 0;
        fn_93_1BB4(self, zero);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
