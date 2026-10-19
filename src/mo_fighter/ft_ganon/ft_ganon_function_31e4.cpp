#pragma force_active on
extern "C" void fn_109_3240(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_31E4(void* self, short flag) {
    if (self != 0) {
        fn_109_3240(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
