#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_3BC4(void* self, short flag) {
    if (self != 0) {
        fn_27_C31CC(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
