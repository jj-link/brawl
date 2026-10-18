#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
void __dl__FPv(void*);

void* fn_91_A188(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            __dt__21ftExtendParamAccesserFv(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
