#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_98_6D78(void*, short);
void* fn_98_6DE4(void*, short);
void* fn_98_6E40(void*, short);
void* fn_98_6E9C(void*, short);
void* fn_98_6EF8(void*, short);
void* fn_98_6F54(void*, short);
}

extern "C" void* fn_98_6CC4(void* object, short deleting) {
    if (object) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(members + 0x224, memberDeleting);
        fn_98_6D78(members + 0x1E8, memberDeleting);
        fn_27_21038(members + 0x1D8, memberDeleting);
        fn_98_6DE4(members + 0x1B8, memberDeleting);
        fn_98_6E40(members + 0x198, memberDeleting);
        fn_98_6E9C(members + 0x160, memberDeleting);
        fn_98_6EF8(members + 0xC4, memberDeleting);
        fn_98_6F54(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
