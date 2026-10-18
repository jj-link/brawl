#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_94E0(void* object, short baseDeleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
