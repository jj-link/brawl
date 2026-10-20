#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_91_7F90(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);

void* fn_91_7FEC(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x25a6c, static_cast<short>(-1));
        fn_91_7F90(static_cast<unsigned char*>(object) + 0x7c, static_cast<short>(-1));
        fn_27_19F4C4(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(-1));
        fn_27_1A55B0(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
