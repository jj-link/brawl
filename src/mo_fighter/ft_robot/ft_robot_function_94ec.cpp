#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_94EC(void* obj, short param) {
    if (obj != 0) {
        __dt__21ftExtendParamAccesserFv(obj, 0);
        if (param > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
