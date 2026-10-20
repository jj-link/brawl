#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CCF74(void*, short);

void operator delete(void*);

extern "C" void* fn_113_153BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x31C, -1);
        fn_27_1A12AC(storage + 0x240, -1);
        fn_27_4CAA0(storage + 0x1BC, -1);
        fn_27_CCF74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
