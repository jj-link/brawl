#pragma force_active on
void operator delete(void*);

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
}

extern "C" void* fn_117_13FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__27soCollisionAttackModuleImplFv(members + 0x124, memberDeleting);
        fn_27_82AD4(members + 0x120, memberDeleting);
        fn_27_4CAA0(members + 0x9C, memberDeleting);
        fn_27_19CA80(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
