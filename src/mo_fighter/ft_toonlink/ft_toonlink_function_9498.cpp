#pragma force_active on
typedef signed short s16;

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_121_93F8(void* owner, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_121_9498(void* self, s16 deleting) {
    if (self != 0) {
        fn_27_C74E8(static_cast<char*>(self) - 0x5C74 + 0x20000, -1);
        fn_121_93F8(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
