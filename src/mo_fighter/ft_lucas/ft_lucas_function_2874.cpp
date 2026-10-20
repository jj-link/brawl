#pragma force_active on
extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* self, short flags);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_27_C7770(void* object, short deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_114_2874(void* self, short deleting) {
    if (self != 0) {
        short flag = -1;
        fn_114_232C((char*)self + 0xdc, flag);
        fn_114_23C8((char*)self + 0xc0, flag);
        fn_114_2408((char*)self + 0x14, flag);
        if (self != 0) {
            fn_27_C7770(self, flag);
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
