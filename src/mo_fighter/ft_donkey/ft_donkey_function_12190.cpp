#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19CA80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_12190(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x124, -1);
        fn_27_82AD4(storage + 0x120, -1);
        fn_27_4CAA0(storage + 0x9C, -1);
        fn_27_19CA80(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
