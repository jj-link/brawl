#pragma force_active on
extern "C" void fn_110_B230(void* object, short deleting);
extern "C" void fn_110_B0FC(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_B290(void* object, short deleting) {
    if (object != 0) {
        fn_110_B230(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_110_B0FC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
