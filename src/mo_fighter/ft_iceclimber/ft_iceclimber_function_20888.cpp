#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CCF74(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_105_20888(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x244, destroy);
        fn_27_82AD4(storage + 0x240, destroy);
        fn_27_4CAA0(storage + 0x1bc, destroy);
        fn_27_CCF74(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
