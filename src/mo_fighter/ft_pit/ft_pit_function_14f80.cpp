#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_112_3698(void*, short);
void* fn_112_36F4(void*, short);
void* fn_112_3750(void*, short);
void* fn_112_1510C(void*, short);
void* fn_112_37DC(void*, short);
void* fn_112_476C(void*, short);
void* fn_112_15768(void*, short);
void* fn_112_4A74(void*, short);
void* fn_112_38D8(void*, short);
void* fn_112_158C0(void*, short);
void* fn_112_3990(void*, short);
void* fn_112_39FC(void*, short);
void* fn_112_3A5C(void*, short);
void* fn_112_3ABC(void*, short);
void* fn_112_4BA8(void*, short);
void* fn_112_3B18(void*, short);
void* fn_112_4C2C(void*, short);
void* fn_112_4CF4(void*, short);
void* fn_112_1591C(void*, short);
void* fn_112_3D68(void*, short);
void* fn_112_3DD4(void*, short);
void* fn_112_3E8C(void*, short);
void* fn_112_3ECC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_112_3F28(void*, short);
}

extern "C" void* fn_112_14F80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;

        fn_112_3698(members + 0x17914, memberDeleting);
        fn_112_36F4(members + 0x178FC, memberDeleting);
        fn_112_3750(members + 0x17760, memberDeleting);
        fn_112_1510C(members + 0x1664, memberDeleting);
        fn_112_37DC(members + 0x1608, memberDeleting);
        fn_112_476C(members + 0x1554, memberDeleting);
        fn_112_15768(members + 0x138C, memberDeleting);
        fn_112_4A74(members + 0x12E8, memberDeleting);
        fn_112_38D8(members + 0x12B4, memberDeleting);
        fn_112_158C0(members + 0x1280, memberDeleting);
        fn_112_3990(members + 0x111C, memberDeleting);
        fn_112_39FC(members + 0x10B4, memberDeleting);
        fn_112_3A5C(members + 0x10A8, memberDeleting);
        fn_112_3ABC(members + 0x1080, memberDeleting);
        fn_112_4BA8(members + 0x0EB0, memberDeleting);
        fn_112_3B18(members + 0x0E4C, memberDeleting);
        fn_112_4C2C(members + 0x0E10, memberDeleting);
        fn_112_4CF4(members + 0x0D58, memberDeleting);
        fn_112_1591C(members + 0x0B10, memberDeleting);
        fn_112_3D68(members + 0x0930, memberDeleting);
        fn_112_3DD4(members + 0x0900, memberDeleting);
        fn_112_3E8C(members + 0x08F0, memberDeleting);
        fn_112_3ECC(members + 0x08D8, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x07F8, memberDeleting);
        fn_112_3F28(object, memberDeleting);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
