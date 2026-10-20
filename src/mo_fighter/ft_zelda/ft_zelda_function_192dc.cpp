#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_104_19354(void* object, short deleting);
extern "C" void* fn_104_195F8(void* object, short deleting);

extern "C" void* fn_104_192DC(void* object, short deleting) {
    if (object != 0) {
        fn_104_19354(static_cast<unsigned char*>(object) + 0x3E74, -1);
        if (object != 0) {
            fn_104_195F8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
