#pragma force_active on
extern "C" {
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);

void* fn_91_6A0C(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x114, static_cast<short>(-1));
        fn_27_CBDE8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
