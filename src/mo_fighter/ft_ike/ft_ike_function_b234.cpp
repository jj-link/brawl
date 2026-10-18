#pragma force_active on
extern "C" void fn_119_B1D4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_B234(void* object, short deleting) {
    if (object != 0) {
        fn_119_B1D4(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
