#pragma force_active on
extern "C" void fn_109_AFB0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_B010(void* object, short deleting) {
    if (object != 0) {
        fn_109_AFB0(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
