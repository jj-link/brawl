#pragma force_active on
extern "C" void* fn_102_321C(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_31C0(void* self, short flag) {
    if (self != 0) {
        fn_102_321C(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
