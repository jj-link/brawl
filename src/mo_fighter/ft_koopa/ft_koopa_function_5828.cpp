#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void fn_27_1A12AC(void*, short);
void fn_27_CB998(void*, short);
void fn_27_CD1F0(void*, short);
}

void operator delete(void*);

extern "C" void* fn_102_5828(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        __dt__27soCollisionAttackModuleImplFv((unsigned char*)object + 0x61c, memberDeleting);
        fn_27_1A12AC((unsigned char*)object + 0x540, memberDeleting);
        fn_27_CB998((unsigned char*)object + 0x2dc, memberDeleting);
        fn_27_CD1F0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
