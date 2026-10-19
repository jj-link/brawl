#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_A54C(void* self, short flag) {
    if (self) {
        fn_27_1A75E4(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
