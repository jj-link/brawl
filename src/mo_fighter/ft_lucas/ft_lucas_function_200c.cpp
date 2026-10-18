#pragma force_active on
extern "C" void fn_27_57BA0(void*, short);
extern "C" void fn_114_208C(void*, short);
extern "C" void fn_114_20E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_200C(void* object, short deleting) {
    if (object != 0) {
        if ((char*)object + 0x20 != 0) {
            fn_27_57BA0((char*)object + 0x20, 0);
        }
        fn_114_208C((char*)object + 0x14, 0);
        fn_114_20E8((char*)object + 0x08, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
