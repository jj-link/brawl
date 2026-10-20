#pragma force_active on
extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* self, short flags);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_25B8(void* self, short flags) {
    short deleting = -1;
    if (self != 0) {
        fn_114_232C((char*)self + 0xDC, deleting);
        fn_114_23C8((char*)self + 0xC0, deleting);
        fn_114_2408((char*)self + 0x14, deleting);
        if (self != 0) {
            fn_27_C7770(self, deleting);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
