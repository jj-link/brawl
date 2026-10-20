#pragma force_active on
extern "C" void __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void fn_27_D2578(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_CCF74(void*, short);

extern "C" void* fn_122_1F850(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x2b4, -1);
        fn_27_D2578(storage + 0x240, -1);
        fn_27_4CAA0(storage + 0x1bc, -1);
        fn_27_CCF74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
