#pragma force_active on
extern "C" void* fn_102_423C(void* p, short n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1BEA0(void* self, short arg1) {
    if (self != 0) {
        fn_102_423C(self, 0);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
