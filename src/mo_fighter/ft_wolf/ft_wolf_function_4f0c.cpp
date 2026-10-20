#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19CF10(void*, short);
extern void operator delete(void*);

extern "C" void* fn_125_4F0C(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv((char*)object + 0x2d4, -1);
        fn_27_82AD4((char*)object + 0x2d0, -1);
        fn_27_4CAA0((char*)object + 0x24c, -1);
        fn_27_19CF10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
