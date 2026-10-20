#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2BC714(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
