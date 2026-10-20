#pragma force_active on
extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* object, short deleting);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_27_C7770(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_14A60(void* object, short deleting) {
    if (object != 0) {
        fn_114_232C((char*)object + 0xDC, -1);
        fn_114_23C8((char*)object + 0xC0, -1);
        fn_114_2408((char*)object + 0x14, -1);

        if (object != 0) {
            fn_27_C7770(object, -1);
        }

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
