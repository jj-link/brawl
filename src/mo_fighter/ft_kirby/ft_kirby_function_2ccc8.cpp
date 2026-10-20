#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CCC8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_96_2CCC8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x1b4, destroy);
        fn_27_82AD4(storage + 0x1b0, destroy);
        fn_27_4CAA0(storage + 0x12c, destroy);
        fn_27_19CCC8(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
