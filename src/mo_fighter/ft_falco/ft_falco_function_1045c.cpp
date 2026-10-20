#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void fn_27_19CCC8(void*, short);

extern "C" void* fn_108_1045C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x1B4, -1);
        fn_27_82AD4(storage + 0x1B0, -1);
        fn_27_4CAA0(storage + 0x12C, -1);
        fn_27_19CCC8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
