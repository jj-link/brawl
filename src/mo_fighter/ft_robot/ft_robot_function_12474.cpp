#pragma force_active on
extern "C" void __dt__19soPostureModuleImplFv(void*, short);
extern "C" void fn_27_1A0184(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12474(void* object, short deleting) {
    if (object != 0) {
        __dt__19soPostureModuleImplFv(
            static_cast<unsigned char*>(object) + 0x6C, -1);
        if (object != 0) {
            fn_27_1A0184(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
