#pragma force_active on
extern "C" {
void* fn_91_93C4(void*, short);
void* fn_91_9358(void*, short);
void* fn_91_9270(void*, short);
void* fn_91_91E4(void*, short);
void* fn_91_9158(void*, short);
void* fn_91_90CC(void*, short);
void* fn_91_9040(void*, short);
void* fn_91_8FB4(void*, short);
void* fn_91_8F28(void*, short);
void* fn_91_8E9C(void*, short);
void* fn_91_8E04(void*, short);

void* fn_91_953C(void* object, short deleting) {
    if (object != 0) {
        fn_91_93C4(static_cast<unsigned char*>(object) + 0x1480, static_cast<short>(-1));
        fn_91_9358(static_cast<unsigned char*>(object) + 0x135c, static_cast<short>(-1));
        fn_91_9270(static_cast<unsigned char*>(object) + 0x1230, static_cast<short>(-1));
        fn_91_91E4(static_cast<unsigned char*>(object) + 0x1104, static_cast<short>(-1));
        fn_91_9158(static_cast<unsigned char*>(object) + 0xfd8, static_cast<short>(-1));
        fn_91_90CC(static_cast<unsigned char*>(object) + 0xeac, static_cast<short>(-1));
        fn_91_9040(static_cast<unsigned char*>(object) + 0xd80, static_cast<short>(-1));
        fn_91_8FB4(static_cast<unsigned char*>(object) + 0xc54, static_cast<short>(-1));
        fn_91_8F28(static_cast<unsigned char*>(object) + 0xb28, static_cast<short>(-1));
        fn_91_8E9C(static_cast<unsigned char*>(object) + 0x9fc, static_cast<short>(-1));
        fn_91_8E04(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
