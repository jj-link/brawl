#pragma force_active on
extern "C" void* fn_27_5BFA0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_2C14(void* self, short flag) {
    if (self != 0) {
        fn_27_5BFA0(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
