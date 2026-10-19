#pragma force_active on
extern "C" void* fn_125_6130(void* ptr, short count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_125_10A7C(void* self, short flag) {
    if (self != 0) {
        fn_125_6130(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
