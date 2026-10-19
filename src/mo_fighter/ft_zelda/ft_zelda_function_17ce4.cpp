#pragma force_active on
typedef signed short s16;

extern "C" void fn_104_17D40(void* self, s16 arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_104_17CE4(void* self, s16 flag) {
    if (self != 0) {
        fn_104_17D40(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
