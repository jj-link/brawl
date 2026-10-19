#pragma force_active on
extern "C" void* fn_122_3820(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_12178(void* self, short flag) {
    if (self != 0) {
        fn_122_3820(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
