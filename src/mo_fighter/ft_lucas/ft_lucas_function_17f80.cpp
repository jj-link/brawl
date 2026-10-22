#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_114_3B68(void*, short);
void* fn_114_3BC4(void*, short);
void* fn_114_3C20(void*, short);
void* fn_114_3C7C(void*, short);
void* fn_114_18134(void*, short);
void* fn_114_3D08(void*, short);
void* fn_114_3E04(void*, short);
void* fn_114_1881C(void*, short);
void* fn_114_41F0(void*, short);
void* fn_114_4324(void*, short);
void* fn_114_4380(void*, short);
void* fn_114_43E4(void*, short);
void* fn_114_4440(void*, short);
void* fn_114_44AC(void*, short);
void* fn_114_450C(void*, short);
void* fn_114_456C(void*, short);
void* fn_114_45C8(void*, short);
void* fn_114_464C(void*, short);
void* fn_114_4718(void*, short);
void* fn_114_4774(void*, short);
void* fn_114_47E0(void*, short);
void* fn_114_5A94(void*, short);
void* fn_114_48DC(void*, short);
void* fn_114_4948(void*, short);
void* fn_114_4A00(void*, short);
void* fn_114_4A40(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_114_4A9C(void*, short);
}

extern "C" void* fn_114_17F80(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_114_3B68(storage + 0xD6BC, destroy);
        fn_114_3BC4(storage + 0xD67C, destroy);
        fn_114_3C20(storage + 0xD664, destroy);
        fn_114_3C7C(storage + 0xD4C8, destroy);
        fn_114_18134(storage + 0x16D0, destroy);
        fn_114_3D08(storage + 0x1674, destroy);
        fn_114_3E04(storage + 0x15C0, destroy);
        fn_114_1881C(storage + 0x13F8, destroy);
        fn_114_41F0(storage + 0x1354, destroy);
        fn_114_4324(storage + 0x1320, destroy);
        fn_114_4380(storage + 0x12FC, destroy);
        fn_114_43E4(storage + 0x12E8, destroy);
        fn_114_4440(storage + 0x1184, destroy);
        fn_114_44AC(storage + 0x111C, destroy);
        fn_114_450C(storage + 0x1110, destroy);
        fn_114_456C(storage + 0x10E8, destroy);
        fn_114_45C8(storage + 0xF18, destroy);
        fn_114_464C(storage + 0xEB4, destroy);
        fn_114_4718(storage + 0xE78, destroy);
        fn_114_4774(storage + 0xDD0, destroy);
        fn_114_47E0(storage + 0xD1C, destroy);
        fn_114_5A94(storage + 0xB10, destroy);
        fn_114_48DC(storage + 0x930, destroy);
        fn_114_4948(storage + 0x900, destroy);
        fn_114_4A00(storage + 0x8F0, destroy);
        fn_114_4A40(storage + 0x8D8, destroy);
        __dt__16soModuleAccesserFv(storage + 0x7F8, destroy);
        fn_114_4A9C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
