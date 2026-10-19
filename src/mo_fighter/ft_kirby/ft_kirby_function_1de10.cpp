#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_96_1E01C(void*, short);

extern "C" void* fn_96_1DE10(void* object, short deleting) {
    if (object != 0) {
        fn_96_1E01C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
