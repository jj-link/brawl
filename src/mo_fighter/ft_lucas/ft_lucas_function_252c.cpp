#pragma force_active on
extern "C" void* fn_114_232C(void*, short);
extern "C" void* fn_114_23C8(void*, short);
extern "C" void* fn_114_2408(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_252C(void* self, short deleting) {
    if (self != 0) {
        fn_114_232C((char*)self + 0xdc, -1);
        fn_114_23C8((char*)self + 0xc0, -1);
        fn_114_2408((char*)self + 0x14, -1);
        if (self != 0) {
            fn_27_C7770(self, -1);
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
