#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CCF74(void*, short);

void operator delete(void*);

void* fn_113_29328(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x244, -1);
        fn_27_82AD4(storage + 0x240, -1);
        fn_27_4CAA0(storage + 0x1bc, -1);
        fn_27_CCF74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
