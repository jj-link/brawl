#pragma force_active on
extern "C" {
void fn_116_1D5FC(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_116_1D5A0(void* self, short flag) {
    if (self != 0) {
        fn_116_1D5FC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
