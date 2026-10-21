#pragma force_active on
extern "C" {
void* fn_91_1DEC(void*, short);
void* fn_91_1D90(void*, short);
void* fn_91_1D34(void*, short);
void* fn_91_1CD8(void*, short);
void* fn_91_1C7C(void*, short);
void* fn_91_1C20(void*, short);
void* fn_91_1BC4(void*, short);
void* fn_91_1B20(void*, short);

#pragma dont_inline on
void* fn_91_1E48(void* object, short deleting) {
    if (object != 0) {
        fn_91_1DEC(static_cast<unsigned char*>(object) + 0x84, static_cast<short>(-1));
        fn_91_1D90(static_cast<unsigned char*>(object) + 0x70, static_cast<short>(-1));
        fn_91_1D34(static_cast<unsigned char*>(object) + 0x5c, static_cast<short>(-1));
        fn_91_1CD8(static_cast<unsigned char*>(object) + 0x48, static_cast<short>(-1));
        fn_91_1C7C(static_cast<unsigned char*>(object) + 0x34, static_cast<short>(-1));
        fn_91_1C20(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(-1));
        fn_91_1BC4(static_cast<unsigned char*>(object) + 0x08, static_cast<short>(-1));
        fn_91_1B20(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
