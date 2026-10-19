#pragma force_active on
extern "C" void* fn_27_1A405C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_58E0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A405C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
