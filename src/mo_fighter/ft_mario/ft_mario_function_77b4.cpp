#pragma force_active on
extern "C" void* fn_91_7754(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_91_77B4(void* object, short deleting) {
    if (object != 0) {
        fn_91_7754(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
