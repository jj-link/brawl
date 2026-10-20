#pragma force_active on
void operator delete(void*);

extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);

extern "C" void* fn_113_5B54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__27soCollisionAttackModuleImplFv(members + 0x61C, memberDeleting);
        fn_27_1A12AC(members + 0x540, memberDeleting);
        fn_27_CB998(members + 0x2DC, memberDeleting);
        fn_27_CD1F0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
