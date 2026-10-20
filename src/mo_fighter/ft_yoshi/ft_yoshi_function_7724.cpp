#pragma force_active on
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_7724(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x61c, -1);
        fn_27_1A12AC(storage + 0x540, -1);
        fn_27_CB998(storage + 0x2dc, -1);
        fn_27_CD1F0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
