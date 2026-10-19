#pragma force_active on
extern "C" void fn_120_17ED0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_17F58(void* self, short shouldDelete) {
    if (self != 0) {
        fn_120_17ED0(self, 0);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
