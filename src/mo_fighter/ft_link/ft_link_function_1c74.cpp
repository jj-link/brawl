#pragma force_active on
typedef signed short s16;

extern "C" void fn_93_1BB4(void* self, s16 arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_93_1C74(void* self, s16 flags) {
    if (self != 0) {
        fn_93_1BB4(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
