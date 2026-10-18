#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_9E74(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            __dt__21ftExtendParamAccesserFv(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
