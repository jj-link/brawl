#pragma force_active on
extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void fn_27_CC984(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_19B94C(void*, short);

extern "C" void* fn_110_FD80(void* object, short deleting) {
    if (object != 0) {
        __dt__24soCollisionHitModuleImplFv((char*)object + 0x274, -1);
        fn_27_CC984((char*)object + 0x230, -1);
        fn_27_4CAA0((char*)object + 0x1ac, -1);
        fn_27_19B94C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
