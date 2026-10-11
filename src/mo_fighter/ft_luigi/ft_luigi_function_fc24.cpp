extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
}

// Destroy the attack module and embedded members before the base subobject.
extern "C" void* fn_99_FC24(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x124, destroyMember);
        fn_27_82AD4(storage + 0x120, destroyMember);
        fn_27_4CAA0(storage + 0x9c, destroyMember);
        fn_27_19CA80(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
