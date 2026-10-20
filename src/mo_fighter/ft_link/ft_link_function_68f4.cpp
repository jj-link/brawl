#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_93_285C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_68F4(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x18,
                                       (short)-1);
        if (object != 0) {
            fn_93_285C(object, (short)0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
