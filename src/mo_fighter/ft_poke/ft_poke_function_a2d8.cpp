#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_A2D8(void* obj, short flags) {
    if (obj != 0) {
        __dt__21ftExtendParamAccesserFv(obj, 0);
        if (flags > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
