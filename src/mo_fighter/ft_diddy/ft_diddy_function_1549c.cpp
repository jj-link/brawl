#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_115_3D94(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1549C(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(
            static_cast<unsigned char*>(object) + 0x18, -1);
        if (object != 0) {
            fn_115_3D94(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
