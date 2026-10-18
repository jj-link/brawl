#pragma force_active on
extern "C" void fn_113_2A10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_15048(void* object, short deleting) {
    if (object != 0) {
        fn_113_2A10(static_cast<unsigned char*>(object) + 0x20, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
