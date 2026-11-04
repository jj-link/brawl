#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_110_2C68(void*, short);
void* fn_110_2CC4(void*, short);
void* fn_110_2D20(void*, short);
void* fn_110_2D7C(void*, short);
void* fn_110_2DD8(void*, short);
void* fn_110_2E34(void*, short);
void* fn_110_2F10(void*, short);
void* fn_110_2F6C(void*, short);
void* fn_110_2FC8(void*, short);
void* fn_110_303C(void*, short);
void* fn_110_30D4(void*, short);
void* fn_110_3130(void*, short);
void* fn_110_1E74C(void*, short);
void* fn_110_50B4(void*, short);
void* fn_110_1EA20(void*, short);
void* fn_110_518C(void*, short);
void* fn_110_5CFC(void*, short);
void* fn_110_4260(void*, short);
void* fn_110_5DD8(void*, short);
void* fn_110_5E4C(void*, short);
void* fn_110_42BC(void*, short);
void* fn_110_5F28(void*, short);
void* fn_110_5F94(void*, short);
void* fn_110_6040(void*, short);
void* fn_110_43D8(void*, short);
void* fn_110_60B4(void*, short);
void* fn_110_6110(void*, short);
void* fn_110_616C(void*, short);
void* fn_110_61C8(void*, short);
void* fn_110_623C(void*, short);
void* fn_110_62B4(void*, short);
void* fn_110_6320(void*, short);
void* fn_110_63B0(void*, short);
void* fn_110_6440(void*, short);
void* fn_110_64C4(void*, short);
void* fn_110_6548(void*, short);
void* fn_110_455C(void*, short);
void* fn_110_45B8(void*, short);
void* fn_110_4624(void*, short);
void* fn_110_667C(void*, short);
void* fn_110_6A40(void*, short);
void* fn_110_6B14(void*, short);
void* fn_110_6B8C(void*, short);
void* fn_110_4884(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_110_6BE8(void*, short);
}

extern "C" void* fn_110_1E4A0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_110_2C68(storage + 0x9310, destroy);
        fn_110_2CC4(storage + 0x92D4, destroy);
        fn_110_2D20(storage + 0x926C, destroy);
        fn_110_2D7C(storage + 0x9220, destroy);
        fn_110_2DD8(storage + 0x90CC, destroy);
        fn_110_2E34(storage + 0x8F6C, destroy);
        fn_110_2F10(storage + 0x8F24, destroy);
        fn_110_2F6C(storage + 0x8EA4, destroy);
        fn_110_2FC8(storage + 0x8DE0, destroy);
        fn_110_303C(storage + 0x8A48, destroy);
        fn_110_30D4(storage + 0x8A18, destroy);
        fn_110_3130(storage + 0x8874, destroy);
        fn_110_1E74C(storage + 0x5D58, destroy);
        fn_110_50B4(storage + 0x5B74, destroy);
        fn_110_1EA20(storage + 0x586C, destroy);
        fn_110_518C(storage + 0x49A8, destroy);
        fn_110_5CFC(storage + 0x48B4, destroy);
        fn_110_4260(storage + 0x4880, destroy);
        fn_110_5DD8(storage + 0x480C, destroy);
        fn_110_5E4C(storage + 0x40E8, destroy);
        fn_110_42BC(storage + 0x40B8, destroy);
        fn_110_5F28(storage + 0x3E84, destroy);
        fn_110_5F94(storage + 0x3E14, destroy);
        fn_110_6040(storage + 0x3D7C, destroy);
        fn_110_43D8(storage + 0x3D44, destroy);
        fn_110_60B4(storage + 0x3D20, destroy);
        fn_110_6110(storage + 0x3CEC, destroy);
        fn_110_616C(storage + 0x3C88, destroy);
        fn_110_61C8(storage + 0x3AD8, destroy);
        fn_110_623C(storage + 0x38E0, destroy);
        fn_110_62B4(storage + 0x3680, destroy);
        fn_110_6320(storage + 0x2C14, destroy);
        fn_110_63B0(storage + 0x29FC, destroy);
        fn_110_6440(storage + 0x20A0, destroy);
        fn_110_64C4(storage + 0x19E4, destroy);
        fn_110_6548(storage + 0x1970, destroy);
        fn_110_455C(storage + 0x1934, destroy);
        fn_110_45B8(storage + 0x188C, destroy);
        fn_110_4624(storage + 0x17D8, destroy);
        fn_110_667C(storage + 0x1444, destroy);
        fn_110_6A40(storage + 0x1180, destroy);
        fn_110_6B14(storage + 0x115C, destroy);
        fn_110_6B8C(storage + 0xAC8, destroy);
        fn_110_4884(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_110_6BE8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
