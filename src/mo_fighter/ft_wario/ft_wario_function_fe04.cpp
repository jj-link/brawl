#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_D2578(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CF10(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_110_FE04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x344, -1);
        fn_27_D2578(storage + 0x2d0, -1);
        fn_27_4CAA0(storage + 0x24c, -1);
        fn_27_19CF10(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
