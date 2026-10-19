#pragma force_active on
extern "C" void fn_41_2B058(void* self, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_41_2B154(void* self, short flag) {
    if (self != 0) {
        fn_41_2B058(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
