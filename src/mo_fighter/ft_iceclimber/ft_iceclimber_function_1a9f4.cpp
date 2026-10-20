#pragma force_active on
extern "C" void* fn_27_CC984(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CC654(void*, short);
extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);

extern "C" void* fn_105_1A9F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(storage + 0x1a4, -1);
        fn_27_CC984(storage + 0x160, -1);
        fn_27_4CAA0(storage + 0xdc, -1);
        fn_27_CC654(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
