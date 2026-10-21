#pragma force_active on
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_91_2EE8(void*, short);
void* fn_91_2E8C(void*, short);
void* fn_91_2BC8(void*, short);
void* fn_91_2E30(void*, short);
void* fn_91_2DB8(void*, short);
void* fn_91_2F44(void*, short);

void* fn_91_2FB0(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x224, static_cast<short>(-1));
        fn_91_2F44(static_cast<unsigned char*>(object) + 0x1e8, static_cast<short>(-1));
        fn_27_21038(static_cast<unsigned char*>(object) + 0x1d8, static_cast<short>(-1));
        fn_91_2EE8(static_cast<unsigned char*>(object) + 0x1b8, static_cast<short>(-1));
        fn_91_2E8C(static_cast<unsigned char*>(object) + 0x198, static_cast<short>(-1));
        fn_91_2BC8(static_cast<unsigned char*>(object) + 0x160, static_cast<short>(-1));
        fn_91_2E30(static_cast<unsigned char*>(object) + 0xc4, static_cast<short>(-1));
        fn_91_2DB8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
