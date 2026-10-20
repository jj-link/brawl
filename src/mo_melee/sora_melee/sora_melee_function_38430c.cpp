#pragma force_active on
struct ftExtendParamAccesser;

extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_38430C(void* object, int deallocationFlag) {
    if (object) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (deallocationFlag > 0)
            __dl__FPv(object);
    }
    return object;
}
