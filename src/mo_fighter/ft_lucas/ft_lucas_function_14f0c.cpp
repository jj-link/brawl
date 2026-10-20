#pragma force_active on
void operator delete(void*);

extern "C" {
void __dt__27soCollisionAttackModuleImplFv(void*, short);
void fn_27_82AD4(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_19CCC8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_114_14F0C(void* object, short deleting) {
    void* result = object;
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__27soCollisionAttackModuleImplFv(members + 0x1b4, memberDeleting);
        fn_27_82AD4(members + 0x1b0, memberDeleting);
        fn_27_4CAA0(members + 0x12c, memberDeleting);
        fn_27_19CCC8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return result;
}
