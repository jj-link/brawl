void operator delete(void*);

extern "C" {
void* fn_98_3B58(void*, short);
void* fn_98_3BB4(void*, short);
void* fn_98_3C10(void*, short);
void* fn_98_3C6C(void*, short);
void* fn_98_138B0(void*, short);
void* fn_98_3FAC(void*, short);
void* fn_98_40E8(void*, short);
void* fn_98_43F8(void*, short);
void* fn_98_452C(void*, short);
void* fn_98_4588(void*, short);
void* fn_98_45E4(void*, short);
void* fn_98_4650(void*, short);
void* fn_98_46B0(void*, short);
void* fn_98_4710(void*, short);
void* fn_98_13910(void*, short);
void* fn_98_476C(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4894(void*, short);
void* fn_98_4900(void*, short);
void* fn_98_4974(void*, short);
void* fn_98_4A74(void*, short);
void* fn_98_4AE0(void*, short);
void* fn_98_4B98(void*, short);
void* fn_98_4BD8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_98_4C34(void*, short);
}

extern "C" void* fn_98_13724(void* object, short deleting) {
    if (object != 0) {
        // Tear down embedded modules in reverse construction order. Their
        // nondeleting flags preserve storage owned by this aggregate.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_98_3B58(members + 0x1A68, memberDeleting);
        fn_98_3BB4(members + 0x1A28, memberDeleting);
        fn_98_3C10(members + 0x1A10, memberDeleting);
        fn_98_3C6C(members + 0x1874, memberDeleting);
        fn_98_138B0(members + 0x17FC, memberDeleting);
        fn_98_3FAC(members + 0x1748, memberDeleting);
        fn_98_40E8(members + 0x1588, memberDeleting);
        fn_98_43F8(members + 0x14E4, memberDeleting);
        fn_98_452C(members + 0x14B0, memberDeleting);
        fn_98_4588(members + 0x1498, memberDeleting);
        fn_98_45E4(members + 0x1334, memberDeleting);
        fn_98_4650(members + 0x12CC, memberDeleting);
        fn_98_46B0(members + 0x12C0, memberDeleting);
        fn_98_4710(members + 0x1298, memberDeleting);
        fn_98_13910(members + 0x0F18, memberDeleting);
        fn_98_476C(members + 0x0EB4, memberDeleting);
        fn_98_4838(members + 0x0E78, memberDeleting);
        fn_98_4894(members + 0x0DD0, memberDeleting);
        fn_98_4900(members + 0x0D1C, memberDeleting);
        fn_98_4974(members + 0x0B10, memberDeleting);
        fn_98_4A74(members + 0x0930, memberDeleting);
        fn_98_4AE0(members + 0x0900, memberDeleting);
        fn_98_4B98(members + 0x08F0, memberDeleting);
        fn_98_4BD8(members + 0x08D8, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x07F8, memberDeleting);
        fn_98_4C34(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
