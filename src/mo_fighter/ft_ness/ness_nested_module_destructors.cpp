void operator delete(void*);
extern "C" {
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_14CF0(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_101_14D60(void*, short);
void* fn_101_15020(void*, short);
void* fn_101_3BA8(void*, short);
void* fn_101_14DF0(void*, short);
void* fn_101_14E7C(void*, short);
void* fn_101_14F08(void*, short);
void* fn_101_14F94(void*, short);
}

extern "C" void* fn_101_14C68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3B4C(members + 0x2368, memberDeleting);
        fn_27_1DBB60(members + 0x2330, memberDeleting);
        fn_101_14CF0(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma dont_inline on
extern "C" void* fn_101_14CF0(void* object, short deleting) {
    if (object != 0) {
        fn_101_14D60(static_cast<unsigned char*>(object) + 0x1CB4, static_cast<short>(-1));
        fn_101_15020(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_101_14D60(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3BA8(members + 0x4B0, memberDeleting);
        fn_101_14DF0(members + 0x384, memberDeleting);
        fn_101_14E7C(members + 0x258, memberDeleting);
        fn_101_14F08(members + 0x12C, memberDeleting);
        fn_101_14F94(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
