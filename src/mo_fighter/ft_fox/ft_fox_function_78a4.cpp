#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_CC984(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19B274(void*, short);
extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);

extern "C" void* fn_97_78A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__24soCollisionHitModuleImplFv(storage + 0x61c, -1);
        fn_27_CC984(storage + 0x5d8, -1);
        fn_27_4CAA0(storage + 0x554, -1);
        fn_27_19B274(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
