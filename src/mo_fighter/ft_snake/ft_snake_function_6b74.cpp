#pragma force_active on
extern "C" void __dt__19soPostureModuleImplFv(void*, short);
extern "C" void fn_27_1A0184(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_6B74(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(object) + 0x6C, destroy);
        if (object != 0) {
            fn_27_1A0184(object, destroy);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
