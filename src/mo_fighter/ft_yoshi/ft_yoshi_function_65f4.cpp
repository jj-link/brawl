#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_95_666C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_65F4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x4B8, (short)-1);
        if (object != 0) {
            fn_95_666C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
