#pragma force_active on
extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* self, short flags);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_201AC(void* self, short flags) {
    if (self != 0) {
        fn_114_232C((char*)self + 0xdc, -1);
        fn_114_23C8((char*)self + 0xc0, -1);
        fn_114_2408((char*)self + 0x14, -1);
        if (self != 0) {
            fn_27_C7770(self, -1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
