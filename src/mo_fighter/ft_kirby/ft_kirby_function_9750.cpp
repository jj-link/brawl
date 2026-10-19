#pragma force_active on
typedef signed short s16;

extern "C" void fn_96_96E0(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_9750(void* self, s16 flag) {
    if (self != 0) {
        fn_96_96E0(self, (s16)-1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
