#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_121_7D9C(void*, short);
void* fn_27_19F98C(void*, short);
void* fn_27_1A58BC(void*, short);

#pragma dont_inline on
void* fn_121_7DF8(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x11CA8, static_cast<short>(-1));
        fn_121_7D9C(static_cast<unsigned char*>(object) + 0xb8, static_cast<short>(-1));
        fn_27_19F98C(static_cast<unsigned char*>(object) + 0x2c, static_cast<short>(-1));
        fn_27_1A58BC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
