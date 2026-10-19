#pragma force_active on
extern "C" void* fn_95_4C88(void*, short);
extern "C" void* fn_95_51B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_4C1C(void* object, short deleting) {
    if (object != 0) {
        fn_95_4C88(static_cast<unsigned char*>(object) + 0x6008, -1);
        fn_95_51B8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
