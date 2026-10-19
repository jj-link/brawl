#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__16soStopModuleImplFv(void*, short);
}

extern "C" void* fn_101_4618(void* object, short deleting) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
