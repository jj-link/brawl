#pragma force_active on
void operator delete(void*);

extern "C" {
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_19FFEC(void*, short);
}

extern "C" void* fn_117_5F3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        __dt__19soPostureModuleImplFv(members + 0x3C, -1);
        if (object != 0) {
            fn_27_19FFEC(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
