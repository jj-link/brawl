#pragma force_active on
extern "C" {
void* __dt__16soStopModuleImplFv(void*, short);

void* fn_91_689C(void* object, short deleting) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
