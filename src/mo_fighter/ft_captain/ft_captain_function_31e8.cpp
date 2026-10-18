#pragma force_active on
extern "C" void fn_100_3244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_31E8(void* self, short flag) {
    if (self != 0) {
        fn_100_3244(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
