#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_1A1114(void*, short);
void* fn_27_CB998(void*, short);
void* fn_27_CD1F0(void*, short);
}

extern "C" void* fn_104_6FF0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x95c, destroy);
        fn_27_1A1114(storage + 0x540, destroy);
        fn_27_CB998(storage + 0x2dc, destroy);
        fn_27_CD1F0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
