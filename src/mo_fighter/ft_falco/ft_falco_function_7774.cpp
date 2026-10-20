#pragma force_active on
extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void* fn_27_CC984(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19B274(void*, short);

extern "C" void* fn_108_7774(void* object, short deleting) {
    if (object != 0) {
        unsigned char* ptr = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(ptr + 0x61C, -1);
        fn_27_CC984(ptr + 0x5D8, -1);
        fn_27_4CAA0(ptr + 0x554, -1);
        fn_27_19B274(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
