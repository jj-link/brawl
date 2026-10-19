#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
void* __dl__FPv(void*);
}

extern "C" void* fn_110_935C(void* ptr, short flags) {
    if (ptr) {
        __dt__21ftExtendParamAccesserFv(ptr, 0);
        if (flags > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
