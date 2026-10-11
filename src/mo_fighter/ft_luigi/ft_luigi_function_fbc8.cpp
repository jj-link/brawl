extern "C" void* __dt__16soStopModuleImplFv(void*, short);

// Destroy the stop module before optionally releasing its storage.
extern "C" void* fn_99_FBC8(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        __dt__16soStopModuleImplFv(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
