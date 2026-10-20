#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19CF10(void*, short);

extern "C" void* fn_94_1C9A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x2D4, -1);
        fn_27_82AD4(storage + 0x2D0, -1);
        fn_27_4CAA0(storage + 0x24C, -1);
        fn_27_19CF10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
