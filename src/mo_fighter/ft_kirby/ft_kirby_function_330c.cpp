#pragma force_active on
extern "C" void fn_96_32CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_330C(void* object, short deleting) {
    if (object != 0) {
        fn_96_32CC(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
