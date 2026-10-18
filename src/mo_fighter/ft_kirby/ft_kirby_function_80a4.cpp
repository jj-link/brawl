#pragma force_active on
extern "C" void fn_96_8044(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_80A4(void* object, short deleting) {
    if (object != 0) {
        fn_96_8044(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
