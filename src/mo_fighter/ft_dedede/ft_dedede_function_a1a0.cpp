#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);

extern "C" void* fn_117_A1A0(void* object, short deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
