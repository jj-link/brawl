#pragma force_active on
extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* self, short flags);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_27_C7770(void* object, short deleting);

extern "C" void* fn_114_202C4(void* self, short flags) {
    if (self != 0) {
        fn_114_232C((char*)self + 0xDC, static_cast<short>(-1));
        fn_114_23C8((char*)self + 0xC0, static_cast<short>(-1));
        fn_114_2408((char*)self + 0x14, static_cast<short>(-1));
        if (self != 0) {
            fn_27_C7770(self, static_cast<short>(-1));
        }
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
