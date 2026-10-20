#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_116_5DBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_5D44(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x190, -1);
        if (object != 0) {
            fn_116_5DBC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
