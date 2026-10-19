#pragma force_active on
extern "C" {
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_19FFEC(void*, short);
}
void operator delete(void*);

// Destructor: destroys the embedded soPostureModuleImpl member, then the base
// class, and optionally frees the storage.
extern "C" void* fn_100_440C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__19soPostureModuleImplFv(storage + 0x3C, destroy);
        if (object != 0) {
            fn_27_19FFEC(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
