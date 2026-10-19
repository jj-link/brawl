#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
void __dl__FPv(void*);

void* fn_125_ACDC(void* ptr, short param) {
    if (ptr) {
        __dt__21ftExtendParamAccesserFv(ptr, 0);
        if (param > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
