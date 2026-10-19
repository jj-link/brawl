#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);

void* fn_91_A1E8(void* object, short deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
