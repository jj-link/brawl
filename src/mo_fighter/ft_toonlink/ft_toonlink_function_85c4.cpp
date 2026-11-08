#include <so/so_module_accesser.h>
#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_121_8568(void*, short);
void* fn_121_850C(void*, short);
void* fn_121_84B0(void*, short);
void* fn_121_8454(void*, short);
void* fn_121_83F8(void*, short);
void* fn_121_8378(void*, short);
void* fn_121_229C(void*, short);
void* fn_121_8244(void*, short);
void* fn_121_81D0(void*, short);
void* fn_121_80D8(void*, short);
void* fn_121_7FE4(void*, short);
void* fn_121_7F4C(void*, short);
void* fn_121_7DF8(void*, short);
void* fn_121_5B0C(void*, short);
void* fn_121_5A34(void*, short);
void* fn_121_544C(void*, short);
void* fn_121_42D4(void*, short);
void* fn_121_2240(void*, short);
void* fn_121_4100(void*, short);
void* fn_121_4014(void*, short);
void* fn_121_3EEC(void*, short);
void* fn_121_3E80(void*, short);
void* fn_121_3DC0(void*, short);
void* fn_121_3C7C(void*, short);
void* fn_121_3BC4(void*, short);
void* fn_121_3B68(void*, short);
void* fn_121_3B0C(void*, short);
void* fn_121_3AB0(void*, short);
void* fn_121_3A3C(void*, short);
void* fn_121_3958(void*, short);
void* fn_121_3850(void*, short);
void* fn_121_3728(void*, short);
void* fn_121_35C4(void*, short);
void* fn_121_346C(void*, short);
void* fn_121_3324(void*, short);
void* fn_121_31E8(void*, short);
void* fn_121_2024(void*, short);
void* fn_121_317C(void*, short);
void* fn_121_1FB0(void*, short);
void* fn_121_2FF4(void*, short);
void* fn_121_29F8(void*, short);
void* fn_121_289C(void*, short);
void* fn_121_2798(void*, short);
void* fn_121_1F54(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_121_2654(void*, short);
}

extern "C" void* fn_121_85C4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_121_8568(storage + 0x18500, destroy);
        fn_121_850C(storage + 0x184C4, destroy);
        fn_121_84B0(storage + 0x1845C, destroy);
        fn_121_8454(storage + 0x18410, destroy);
        fn_121_83F8(storage + 0x182BC, destroy);
        fn_121_8378(storage + 0x181AC, destroy);
        fn_121_229C(storage + 0x18164, destroy);
        fn_121_8244(storage + 0x180E4, destroy);
        fn_121_81D0(storage + 0x18020, destroy);
        fn_121_80D8(storage + 0x17CAC, destroy);
        fn_121_7FE4(storage + 0x17C7C, destroy);
        fn_121_7F4C(storage + 0x17AD8, destroy);
        fn_121_7DF8(storage + 0x5DF4, destroy);
        fn_121_5B0C(storage + 0x5C10, destroy);
        fn_121_5A34(storage + 0x5908, destroy);
        fn_121_544C(storage + 0x4A98, destroy);
        fn_121_42D4(storage + 0x49A4, destroy);
        fn_121_2240(storage + 0x4970, destroy);
        fn_121_4100(storage + 0x48FC, destroy);
        fn_121_4014(storage + 0x41D8, destroy);
        fn_121_3EEC(storage + 0x41A8, destroy);
        fn_121_3E80(storage + 0x4010, destroy);
        fn_121_3DC0(storage + 0x3FA0, destroy);
        fn_121_3C7C(storage + 0x3F08, destroy);
        fn_121_3BC4(storage + 0x3ED0, destroy);
        fn_121_3B68(storage + 0x3EAC, destroy);
        fn_121_3B0C(storage + 0x3E78, destroy);
        fn_121_3AB0(storage + 0x3E14, destroy);
        fn_121_3A3C(storage + 0x3C64, destroy);
        fn_121_3958(storage + 0x3A6C, destroy);
        fn_121_3850(storage + 0x380C, destroy);
        fn_121_3728(storage + 0x2DA0, destroy);
        fn_121_35C4(storage + 0x29F8, destroy);
        fn_121_346C(storage + 0x209C, destroy);
        fn_121_3324(storage + 0x19E0, destroy);
        fn_121_31E8(storage + 0x196C, destroy);
        fn_121_2024(storage + 0x1930, destroy);
        fn_121_317C(storage + 0x1888, destroy);
        fn_121_1FB0(storage + 0x17D4, destroy);
        fn_121_2FF4(storage + 0x1440, destroy);
        fn_121_29F8(storage + 0x1180, destroy);
        fn_121_289C(storage + 0x115C, destroy);
        fn_121_2798(storage + 0xAC8, destroy);
        fn_121_1F54(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_121_2654(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
