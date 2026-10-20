#pragma force_active on
extern "C" {
void* fn_91_2818(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);

#pragma dont_inline on
void* fn_91_6A78(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x18, static_cast<short>(-1));
        if (object != 0) fn_91_2818(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
