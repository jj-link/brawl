#pragma force_active on
extern "C" void* fn_108_100D4(void*, short);
extern "C" void* fn_108_101F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_10064(void* object, short deleting) {
    if (object != 0) {
        fn_108_100D4(static_cast<unsigned char*>(object) + 0x1874, -1);
        fn_108_101F0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
