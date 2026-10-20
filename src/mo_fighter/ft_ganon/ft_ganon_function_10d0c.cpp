#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_CB800(void*, short);
extern "C" void* fn_27_19CF10(void*, short);
extern void operator delete(void*);

extern "C" void* fn_109_10D0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x34C, -1);
        fn_27_82AD4(storage + 0x348, -1);
        fn_27_CB800(storage + 0x24C, -1);
        fn_27_19CF10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
