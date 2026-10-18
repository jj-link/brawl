#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_9DC0(void* object, int baseDeleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if ((short)baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
