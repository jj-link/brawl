#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_1A12AC(void*, short);
void* fn_27_CB998(void*, short);
void* fn_27_CD1F0(void*, short);
void __dl__FPv(void*);

void* fn_91_3274(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv(static_cast<unsigned char*>(object) + 0x61c, static_cast<short>(-1));
        fn_27_1A12AC(static_cast<unsigned char*>(object) + 0x540, static_cast<short>(-1));
        fn_27_CB998(static_cast<unsigned char*>(object) + 0x2dc, static_cast<short>(-1));
        fn_27_CD1F0(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
