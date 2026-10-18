#pragma force_active on
extern "C" void fn_96_1239C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_123FC(void* object, short deleting) {
    if (object != 0) {
        fn_96_1239C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
