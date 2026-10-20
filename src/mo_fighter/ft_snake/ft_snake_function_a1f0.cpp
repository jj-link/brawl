#pragma force_active on
extern "C" void* __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void* fn_27_CC984(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19B704(void*, short);

extern "C" void* fn_122_A1F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(storage + 0x8f4, -1);
        fn_27_CC984(storage + 0x8b0, -1);
        fn_27_4CAA0(storage + 0x82c, -1);
        fn_27_19B704(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
