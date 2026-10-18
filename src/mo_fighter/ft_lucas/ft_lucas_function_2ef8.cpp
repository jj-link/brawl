#pragma force_active on
extern "C" void* fn_27_B81C4(void*, short);
extern "C" void* fn_114_2F78(void*, short);
extern "C" void* fn_27_198034(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_2EF8(void* object, short deleting) {
    if (object != 0) {
        fn_27_B81C4((char*)object + 0xA4, -1);
        fn_114_2F78((char*)object + 0x48, -1);
        if (object != 0) {
            fn_27_198034(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
