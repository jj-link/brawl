#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_101_4A6C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_101_49F4(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(
            static_cast<unsigned char*>(object) + 0x18, static_cast<short>(-1));
        if (object != 0) {
            fn_101_4A6C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
