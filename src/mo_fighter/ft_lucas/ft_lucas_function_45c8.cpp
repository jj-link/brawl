#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_114_45C8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(storage + 0x124, destroy);
        fn_27_82AD4(storage + 0x120, destroy);
        fn_27_4CAA0(storage + 0x9c, destroy);
        fn_27_19CA80(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
