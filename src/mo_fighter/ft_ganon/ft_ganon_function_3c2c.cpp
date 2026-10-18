#pragma force_active on
extern "C" void fn_109_1EB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_3C2C(void* object, short deleting) {
    if (object != 0) {
        fn_109_1EB4(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
