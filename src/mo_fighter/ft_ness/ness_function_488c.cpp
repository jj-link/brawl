#pragma force_active on
void operator delete(void*);
extern "C" {
void __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_19FFEC(void*, short);
}

extern "C" void* fn_101_488C(void* object, short deleting) {
    if (object != 0) {
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(object) + 0x3C, static_cast<short>(-1));
        if (object != 0) {
            fn_27_19FFEC(object, static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
