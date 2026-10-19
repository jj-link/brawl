#pragma force_active on
extern "C" void fn_63_2C40(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_63_15534(void* self, int flag) {
    if (self != 0) {
        fn_63_2C40(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
