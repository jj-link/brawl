#pragma force_active on
extern "C" {
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_19FFEC(void*, short);

#pragma dont_inline on
void* fn_91_1F5C(void* object, short deleting) {
    if (object != 0) {
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(object) + 0x3c, static_cast<short>(-1));
        if (object != 0) fn_27_19FFEC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
