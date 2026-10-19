#pragma force_active on
extern "C" void fn_120_15BD4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_15C44(void* self, short flag) {
    if (self != 0) {
        fn_120_15BD4(self, (short)0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
