#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_18824(void* object, int deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
