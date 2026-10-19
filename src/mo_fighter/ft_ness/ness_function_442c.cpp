#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__22soControllerModuleImplFv(void*, short);
}

extern "C" void* fn_101_442C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x4;
        if (member != 0) {
            __dt__22soControllerModuleImplFv(member, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
