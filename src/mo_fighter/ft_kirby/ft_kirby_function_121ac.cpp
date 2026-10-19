#pragma force_active on
extern "C" void* fn_96_84BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_121AC(void* object, short deleteFlag) {
    if (object != 0) {
        fn_96_84BC(object, 0);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
