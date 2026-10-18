#pragma force_active on
void operator delete(void*);

extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);

extern "C" void* fn_116_187C4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            __dt__21ftExtendParamAccesserFv(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
