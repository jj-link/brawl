#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19CF10(void*, short);

extern "C" void* fn_119_11BB8(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv(static_cast<unsigned char*>(object) + 0x2d4, -1);
        fn_27_82AD4(static_cast<unsigned char*>(object) + 0x2d0, -1);
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x24c, -1);
        fn_27_19CF10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
