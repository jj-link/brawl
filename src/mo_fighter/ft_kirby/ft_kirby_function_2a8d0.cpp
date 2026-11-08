#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_8A88(void*, short);
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_6C64(void*, short);
void* fn_96_2874(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_8AE4(void*, short);
void* fn_96_8B78(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_2AA68(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_8C7C(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_259C(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_8D00(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_96_7F18(void*, short);
}

extern "C" void* fn_96_2A8D0(void* object, short deleting) {
    if (object) {
        char* p = (char*)object;
        fn_96_8A88(p + 0x19B8, -1);
        fn_96_7C18(p + 0x1978, -1);
        fn_96_6C08(p + 0x1960, -1);
        fn_96_6C64(p + 0x1808, -1);
        fn_96_2874(p + 0x17BC, -1);
        fn_96_7C74(p + 0x1624, -1);
        fn_96_6D1C(p + 0x15C4, -1);
        fn_96_8AE4(p + 0x1510, -1);
        fn_96_8B78(p + 0x1350, -1);
        fn_96_6D7C(p + 0x12AC, -1);
        fn_96_27B8(p + 0x1278, -1);
        fn_96_2AA68(p + 0x1244, -1);
        fn_96_6E60(p + 0x10E0, -1);
        fn_96_7DE4(p + 0x1078, -1);
        fn_96_6ECC(p + 0x106C, -1);
        fn_96_7E44(p + 0x1044, -1);
        fn_96_8C7C(p + 0x0E74, -1);
        fn_96_6F2C(p + 0x0E10, -1);
        fn_96_259C(p + 0x0DD4, -1);
        fn_96_24BC(p + 0x0D1C, -1);
        fn_96_8D00(p + 0x0B10, -1);
        fn_96_7040(p + 0x0930, -1);
        fn_96_70AC(p + 0x0900, -1);
        fn_96_7124(p + 0x08F0, -1);
        fn_96_2460(p + 0x08D8, -1);
        __dt__16soModuleAccesserFv(p + 0x07F8, -1);
        fn_96_7F18(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
