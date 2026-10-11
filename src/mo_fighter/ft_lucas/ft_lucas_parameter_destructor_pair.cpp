#include <ft/ft_extend_param_accesser.h>

extern "C" void __dl__FPv(void* object);

// The shared destructor entry includes the ABI's hidden deleting flag.
// These base-teardown calls require zero, not explicit destruction's minus one.
extern "C" void* __dt__21ftExtendParamAccesserFv(ftExtendParamAccesser* object, s16 deleting);

// Retain the original unreferenced hook and second destructor in the REL.
#pragma force_active on

extern "C" void fn_114_C854(void*) { }

extern "C" ftExtendParamAccesser* fn_114_C858(ftExtendParamAccesser* object, s16 deleting) {
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

extern "C" ftExtendParamAccesser* fn_114_C8B8(ftExtendParamAccesser* object, s16 deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
