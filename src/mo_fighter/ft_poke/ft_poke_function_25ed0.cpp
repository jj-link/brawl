#pragma force_active on
extern "C" void* fn_116_25F2C(void* object, short deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_116_25ED0(void* self, short deleting) {
    if (self != 0) {
        fn_116_25F2C(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
