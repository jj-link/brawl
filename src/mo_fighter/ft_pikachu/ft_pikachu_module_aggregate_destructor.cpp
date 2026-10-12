void operator delete(void*);

extern "C" {
void* fn_98_2B2C(void*, short);
void* fn_98_2B88(void*, short);
void* fn_98_2BE4(void*, short);
void* fn_98_2C40(void*, short);
void* fn_98_2C9C(void*, short);
void* fn_98_2CF8(void*, short);
void* fn_98_2DD4(void*, short);
void* fn_98_2E30(void*, short);
void* fn_98_2E8C(void*, short);
void* fn_98_2F00(void*, short);
void* fn_98_2F98(void*, short);
void* fn_98_2FF4(void*, short);
void* fn_98_3144(void*, short);
void* fn_98_5654(void*, short);
void* fn_98_56B4(void*, short);
void* fn_98_5808(void*, short);
void* fn_98_6378(void*, short);
void* fn_98_452C(void*, short);
void* fn_98_5384(void*, short);
void* fn_98_6454(void*, short);
void* fn_98_6530(void*, short);
void* fn_98_658C(void*, short);
void* fn_98_65F8(void*, short);
void* fn_98_66A4(void*, short);
void* fn_98_6718(void*, short);
void* fn_98_6774(void*, short);
void* fn_98_67D0(void*, short);
void* fn_98_682C(void*, short);
void* fn_98_6888(void*, short);
void* fn_98_68FC(void*, short);
void* fn_98_6968(void*, short);
void* fn_98_69F8(void*, short);
void* fn_98_6A88(void*, short);
void* fn_98_6B0C(void*, short);
void* fn_98_6B90(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4894(void*, short);
void* fn_98_4900(void*, short);
void* fn_98_6CC4(void*, short);
void* fn_98_7088(void*, short);
void* fn_98_715C(void*, short);
void* fn_98_71D4(void*, short);
void* fn_98_4BD8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_98_7230(void*, short);
}

extern "C" void* fn_98_288C(void* object, short deleting) {
    if (object != 0) {
        // Embedded modules are destroyed in reverse construction order without
        // releasing their storage; only the aggregate owns its allocation.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_98_2B2C(members + 0x28F90, memberDeleting);
        fn_98_2B88(members + 0x28F54, memberDeleting);
        fn_98_2BE4(members + 0x28EEC, memberDeleting);
        fn_98_2C40(members + 0x28EA0, memberDeleting);
        fn_98_2C9C(members + 0x28D4C, memberDeleting);
        fn_98_2CF8(members + 0x28C3C, memberDeleting);
        fn_98_2DD4(members + 0x28BF4, memberDeleting);
        fn_98_2E30(members + 0x28B74, memberDeleting);
        fn_98_2E8C(members + 0x28AB0, memberDeleting);
        fn_98_2F00(members + 0x2873C, memberDeleting);
        fn_98_2F98(members + 0x2870C, memberDeleting);
        fn_98_2FF4(members + 0x28568, memberDeleting);
        fn_98_3144(members + 0x5A80, memberDeleting);
        fn_98_5654(members + 0x589C, memberDeleting);
        fn_98_56B4(members + 0x5594, memberDeleting);
        fn_98_5808(members + 0x4714, memberDeleting);
        fn_98_6378(members + 0x4620, memberDeleting);
        fn_98_452C(members + 0x45EC, memberDeleting);
        fn_98_5384(members + 0x4578, memberDeleting);
        fn_98_6454(members + 0x3E54, memberDeleting);
        fn_98_6530(members + 0x3E24, memberDeleting);
        fn_98_658C(members + 0x3C8C, memberDeleting);
        fn_98_65F8(members + 0x3C1C, memberDeleting);
        fn_98_66A4(members + 0x3B84, memberDeleting);
        fn_98_6718(members + 0x3B4C, memberDeleting);
        fn_98_6774(members + 0x3B28, memberDeleting);
        fn_98_67D0(members + 0x3AF4, memberDeleting);
        fn_98_682C(members + 0x3A90, memberDeleting);
        fn_98_6888(members + 0x38E0, memberDeleting);
        fn_98_68FC(members + 0x367C, memberDeleting);
        fn_98_6968(members + 0x2C10, memberDeleting);
        fn_98_69F8(members + 0x29F8, memberDeleting);
        fn_98_6A88(members + 0x209C, memberDeleting);
        fn_98_6B0C(members + 0x19E0, memberDeleting);
        fn_98_6B90(members + 0x196C, memberDeleting);
        fn_98_4838(members + 0x1930, memberDeleting);
        fn_98_4894(members + 0x1888, memberDeleting);
        fn_98_4900(members + 0x17D4, memberDeleting);
        fn_98_6CC4(members + 0x1440, memberDeleting);
        fn_98_7088(members + 0x1180, memberDeleting);
        fn_98_715C(members + 0x115C, memberDeleting);
        fn_98_71D4(members + 0xAC8, memberDeleting);
        fn_98_4BD8(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_98_7230(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
