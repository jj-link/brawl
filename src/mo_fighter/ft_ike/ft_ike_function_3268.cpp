#pragma force_active on
typedef signed short s16;

extern "C" void* fn_119_32C4(void* object, s16 deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_119_3268(void* self, s16 deleting) {
    if (self != 0) {
        fn_119_32C4(self, -1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
