#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_8534(void* object, short deleting) {
    if (object) {
        if (object) {
            short destroyBase = 0;
            __dt__21ftExtendParamAccesserFv(object, destroyBase);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
