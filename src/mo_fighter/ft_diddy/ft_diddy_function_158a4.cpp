#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19CA80(void*, short);
void operator delete(void*);

extern "C" void* fn_115_158A4(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        __dt__27soCollisionAttackModuleImplFv((unsigned char*)object + 0x124, destroy);
        fn_27_82AD4((unsigned char*)object + 0x120, destroy);
        fn_27_4CAA0((unsigned char*)object + 0x9c, destroy);
        fn_27_19CA80(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
