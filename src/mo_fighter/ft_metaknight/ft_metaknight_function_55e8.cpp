#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_1A1444(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CD1F0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_111_55E8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x5dc, destroy);
        fn_27_1A1444(storage + 0x360, destroy);
        fn_27_4CAA0(storage + 0x2dc, destroy);
        fn_27_CD1F0(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
