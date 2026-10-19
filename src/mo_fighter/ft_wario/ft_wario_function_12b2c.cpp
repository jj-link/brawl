#pragma force_active on
extern "C" {
void fn_110_4FF4(void* p, short n);
void __dl__FPv(void* p);
}

extern "C" void* fn_110_12B2C(void* self, short n) {
    if (self != 0) {
        fn_110_4FF4(self, 0);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
