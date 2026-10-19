#pragma force_active on
extern "C" void* fn_95_5938(void*, short);
extern "C" void* fn_95_5B70(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_58CC(void* object, short deleting) {
    if (object != 0) {
        fn_95_5938(static_cast<unsigned char*>(object) + 0x5DB0, -1);
        fn_95_5B70(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
