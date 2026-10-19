#pragma force_active on
extern "C" void fn_97_6208(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_97_10B64(void* self, short flag) {
    if (self != 0) {
        fn_97_6208(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
