#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
}

extern "C" void* fn_101_CE7C(void* object, short deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
