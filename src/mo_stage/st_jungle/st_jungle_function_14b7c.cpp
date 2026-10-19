#pragma force_active on
extern "C" void fn_51_289C(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_51_14B7C(void* self, int flags) {
    if (self != 0) {
        fn_51_289C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
