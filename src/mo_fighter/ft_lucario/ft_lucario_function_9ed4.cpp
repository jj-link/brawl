#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);

extern "C" void* fn_118_9ED4(void* object, short deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
