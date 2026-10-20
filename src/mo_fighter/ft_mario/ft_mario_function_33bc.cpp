#pragma force_active on
extern "C" {
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19B704(void*, short);

void* fn_91_33BC(void* object, short deleting) {
    if (object != 0) {
        __dt__24soCollisionHitModuleImplFv(static_cast<unsigned char*>(object) + 0x8f4, static_cast<short>(-1));
        fn_27_CC984(static_cast<unsigned char*>(object) + 0x8b0, static_cast<short>(-1));
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x82c, static_cast<short>(-1));
        fn_27_19B704(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
