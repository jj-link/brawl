#pragma force_active on
extern "C" void* __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void* fn_27_CC984(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19B02C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_77CC(void* object, short destroying) {
    if (object != 0) {
        short destroy = -1;
        __dt__24soCollisionHitModuleImplFv(static_cast<unsigned char*>(object) + 0x5B4, destroy);
        fn_27_CC984(static_cast<unsigned char*>(object) + 0x570, destroy);
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x4EC, destroy);
        fn_27_19B02C(object, destroy);
        if (destroying > 0) {
            operator delete(object);
        }
    }
    return object;
}
