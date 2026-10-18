#pragma force_active on
extern "C" void* fn_96_8DD8(void* object, short deleting);
extern "C" void* fn_96_8668(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_96_8E38(void* object, short deleting) {
    if (object != 0) {
        fn_96_8DD8(static_cast<char*>(object) + 0xAE98, -1);
        if (object != 0) {
            fn_96_8668(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
