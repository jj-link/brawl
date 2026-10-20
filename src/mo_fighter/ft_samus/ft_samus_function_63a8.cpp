#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_1A12AC(void*, short);
void* fn_27_CB998(void*, short);
void* fn_27_CD1F0(void*, short);
}

extern "C" void* fn_94_63A8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x61c, destroy);
        fn_27_1A12AC(storage + 0x540, destroy);
        fn_27_CB998(storage + 0x2dc, destroy);
        fn_27_CD1F0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
