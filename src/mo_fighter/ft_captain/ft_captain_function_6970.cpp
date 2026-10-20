#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_100_4648(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_6970(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, -1);
        if (object != 0) {
            fn_100_4648(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
