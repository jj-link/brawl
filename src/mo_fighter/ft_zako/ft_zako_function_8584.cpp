#pragma force_active on
extern "C" void* fn_126_8524(void* object, short deleting);
extern "C" void fn_126_83F0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_8584(void* object, short deleting) {
    if (object != 0) {
        fn_126_8524(static_cast<unsigned char*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_126_83F0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
