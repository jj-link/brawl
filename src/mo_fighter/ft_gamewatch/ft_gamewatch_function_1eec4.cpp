#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void fn_27_19D3A0(void*, short);

extern "C" void* fn_107_1EEC4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x514, -1);
        fn_27_82AD4(storage + 0x510, -1);
        fn_27_4CAA0(storage + 0x48c, -1);
        fn_27_19D3A0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
