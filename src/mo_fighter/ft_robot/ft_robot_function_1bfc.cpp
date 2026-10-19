#pragma force_active on
typedef signed short s16;

extern "C" {
void __dl__FPv(void* p);
void fn_120_1B3C(void* self, s16 arg);

void* fn_120_1BFC(void* self, s16 flag) {
    if (self != 0) {
        s16 zero = 0;
        fn_120_1B3C(self, zero);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
