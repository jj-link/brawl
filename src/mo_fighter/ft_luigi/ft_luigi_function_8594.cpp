#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_8594(void* object, short deleting) {
    if (object) {
        int destroyBase = 0;
        __dt__21ftExtendParamAccesserFv(object, (short)destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
