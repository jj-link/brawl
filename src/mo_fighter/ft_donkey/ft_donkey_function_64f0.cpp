#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);

extern "C" void* fn_92_64F0(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv(reinterpret_cast<unsigned char*>(object) + 0x61C, -1);
        fn_27_1A12AC(reinterpret_cast<unsigned char*>(object) + 0x540, -1);
        fn_27_CB998(reinterpret_cast<unsigned char*>(object) + 0x2DC, -1);
        fn_27_CD1F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
