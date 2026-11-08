#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_8568(void*, short);
void* fn_93_850C(void*, short);
void* fn_93_84B0(void*, short);
void* fn_93_8454(void*, short);
void* fn_93_83F8(void*, short);
void* fn_93_8378(void*, short);
void* fn_93_229C(void*, short);
void* fn_93_8244(void*, short);
void* fn_93_81D0(void*, short);
void* fn_93_80D8(void*, short);
void* fn_93_7FE4(void*, short);
void* fn_93_7F4C(void*, short);
void* fn_93_7DF8(void*, short);
void* fn_93_5B0C(void*, short);
void* fn_93_5A34(void*, short);
void* fn_93_544C(void*, short);
void* fn_93_42D4(void*, short);
void* fn_93_2240(void*, short);
void* fn_93_4100(void*, short);
void* fn_93_4014(void*, short);
void* fn_93_3EEC(void*, short);
void* fn_93_3E80(void*, short);
void* fn_93_3DC0(void*, short);
void* fn_93_3C7C(void*, short);
void* fn_93_3BC4(void*, short);
void* fn_93_3B68(void*, short);
void* fn_93_3B0C(void*, short);
void* fn_93_3AB0(void*, short);
void* fn_93_3A3C(void*, short);
void* fn_93_3958(void*, short);
void* fn_93_3850(void*, short);
void* fn_93_3728(void*, short);
void* fn_93_35C4(void*, short);
void* fn_93_346C(void*, short);
void* fn_93_3324(void*, short);
void* fn_93_31E8(void*, short);
void* fn_93_2024(void*, short);
void* fn_93_317C(void*, short);
void* fn_93_1FB0(void*, short);
void* fn_93_2FF4(void*, short);
void* fn_93_29F8(void*, short);
void* fn_93_289C(void*, short);
void* fn_93_2798(void*, short);
void* fn_93_1F54(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_93_2654(void*, short);
}

extern "C" void* fn_93_85C4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_93_8568(storage + 0x184C4, destroy);
        fn_93_850C(storage + 0x18488, destroy);
        fn_93_84B0(storage + 0x18420, destroy);
        fn_93_8454(storage + 0x183D4, destroy);
        fn_93_83F8(storage + 0x18280, destroy);
        fn_93_8378(storage + 0x18170, destroy);
        fn_93_229C(storage + 0x18128, destroy);
        fn_93_8244(storage + 0x180A8, destroy);
        fn_93_81D0(storage + 0x17FE4, destroy);
        fn_93_80D8(storage + 0x17C70, destroy);
        fn_93_7FE4(storage + 0x17C40, destroy);
        fn_93_7F4C(storage + 0x17A9C, destroy);
        fn_93_7DF8(storage + 0x5DF4, destroy);
        fn_93_5B0C(storage + 0x5C10, destroy);
        fn_93_5A34(storage + 0x5908, destroy);
        fn_93_544C(storage + 0x4A98, destroy);
        fn_93_42D4(storage + 0x49A4, destroy);
        fn_93_2240(storage + 0x4970, destroy);
        fn_93_4100(storage + 0x48FC, destroy);
        fn_93_4014(storage + 0x41D8, destroy);
        fn_93_3EEC(storage + 0x41A8, destroy);
        fn_93_3E80(storage + 0x4010, destroy);
        fn_93_3DC0(storage + 0x3FA0, destroy);
        fn_93_3C7C(storage + 0x3F08, destroy);
        fn_93_3BC4(storage + 0x3ED0, destroy);
        fn_93_3B68(storage + 0x3EAC, destroy);
        fn_93_3B0C(storage + 0x3E78, destroy);
        fn_93_3AB0(storage + 0x3E14, destroy);
        fn_93_3A3C(storage + 0x3C64, destroy);
        fn_93_3958(storage + 0x3A6C, destroy);
        fn_93_3850(storage + 0x380C, destroy);
        fn_93_3728(storage + 0x2DA0, destroy);
        fn_93_35C4(storage + 0x29F8, destroy);
        fn_93_346C(storage + 0x209C, destroy);
        fn_93_3324(storage + 0x19E0, destroy);
        fn_93_31E8(storage + 0x196C, destroy);
        fn_93_2024(storage + 0x1930, destroy);
        fn_93_317C(storage + 0x1888, destroy);
        fn_93_1FB0(storage + 0x17D4, destroy);
        fn_93_2FF4(storage + 0x1440, destroy);
        fn_93_29F8(storage + 0x1180, destroy);
        fn_93_289C(storage + 0x115C, destroy);
        fn_93_2798(storage + 0xAC8, destroy);
        fn_93_1F54(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_93_2654(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}