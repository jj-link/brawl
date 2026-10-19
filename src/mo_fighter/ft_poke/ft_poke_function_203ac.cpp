#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_203AC(void* object, int flags) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if ((short)flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
