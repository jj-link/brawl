#pragma force_active on
typedef signed short s16;

extern "C" void fn_122_3254(void* self, s16 flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_122_31F8(void* self, s16 flag) {
    if (self != 0) {
        fn_122_3254(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
