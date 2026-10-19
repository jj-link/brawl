#pragma force_active on
extern "C" void fn_96_84BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_8460(void* object, short deleting) {
    if (object != 0) {
        fn_96_84BC(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
