#pragma force_active on
void operator delete(void*);

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19D158(void*, short);
}

extern "C" void* fn_105_1AA78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv(members + 0x484, destroy);
        fn_27_82AD4(members + 0x480, destroy);
        fn_27_4CAA0(members + 0x3FC, destroy);
        fn_27_19D158(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
