#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_108_4570(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_44F8(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(
            static_cast<unsigned char*>(object) + 0x18, -1);
        if (object != 0) {
            fn_108_4570(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
