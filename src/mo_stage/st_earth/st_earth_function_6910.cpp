#pragma force_active on
extern "C" void fn_66_2C60(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_66_6910(void* self, int size) {
    if (self != 0) {
        fn_66_2C60(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
