#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5B00(void* self, short arg2) {
    if (self != 0) {
        fn_27_1A75E4(self, -1);
        if (arg2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
