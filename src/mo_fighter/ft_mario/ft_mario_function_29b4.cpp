#pragma force_active on
extern "C" {
void* fn_91_2958(void*, short);
void* fn_27_19A83C(void*, short);
void __dt__17soModelModuleImplFv(void*, short);

void* fn_91_29B4(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x1f4, static_cast<short>(-1));
        fn_91_2958(static_cast<unsigned char*>(object) + 0x1ac, static_cast<short>(-1));
        fn_27_19A83C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
