#pragma force_active on
extern "C" void* fn_101_5994(void*, short);
extern "C" void* fn_101_18B94(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_101_18B28(void* object, short deleting) {
    if (object != 0) {
        fn_101_5994(static_cast<unsigned char*>(object) + 0x5E94, static_cast<short>(-1));
        fn_101_18B94(static_cast<unsigned char*>(object) + 0x4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
