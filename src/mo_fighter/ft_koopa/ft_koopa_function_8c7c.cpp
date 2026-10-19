#pragma force_active on
extern "C" {

void* __dt__21ftExtendParamAccesserFv(void*, short);
void __dl__FPv(void*);

void* fn_102_8C7C(void* obj, short p) {
    if (obj != 0) {
        __dt__21ftExtendParamAccesserFv(obj, 0);
        if (p > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

}
