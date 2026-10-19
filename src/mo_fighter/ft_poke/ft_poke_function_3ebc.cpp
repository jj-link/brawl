#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_3EBC(void* self, short flag) {
    if (self != 0) {
        fn_27_A1E80(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
