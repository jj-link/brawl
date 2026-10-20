#pragma force_active on
extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void fn_27_CC984(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_CC654(void*, short);

extern "C" void* fn_113_15338(void* object, short destroying) {
    if (object != 0) {
        __dt__24soCollisionHitModuleImplFv(static_cast<char*>(object) + 0x1a4, -1);
        fn_27_CC984(static_cast<char*>(object) + 0x160, -1);
        fn_27_4CAA0(static_cast<char*>(object) + 0xdc, -1);
        fn_27_CC654(object, -1);
        if (destroying > 0) {
            operator delete(object);
        }
    }
    return object;
}
