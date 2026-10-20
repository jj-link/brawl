#pragma force_active on
void operator delete(void*);

extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);

extern "C" void* fn_114_8280(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x61C, destroy);
        fn_27_1A12AC(storage + 0x540, destroy);
        fn_27_CB998(storage + 0x2DC, destroy);
        fn_27_CD1F0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
