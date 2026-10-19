#pragma force_active on
extern "C" void* fn_109_A4B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_A574(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_109_A4B4(static_cast<unsigned char*>(object) + 4,
                         static_cast<short>(-1));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
