#pragma force_active on
extern "C" void* fn_104_C7B4(void* object, short deleting);
extern "C" void* fn_104_C680(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C814(void* object, short deleting) {
    if (object != 0) {
        fn_104_C7B4(static_cast<char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_104_C680(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
