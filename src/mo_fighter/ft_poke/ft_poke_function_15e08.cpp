#pragma force_active on

void operator delete(void*);

extern "C" {
void* fn_116_2B58(void*, short);
void* fn_116_2BB4(void*, short);
void* fn_116_2C10(void*, short);
void* fn_116_2C6C(void*, short);
void* fn_116_2CC8(void*, short);
void* fn_116_2D24(void*, short);
void* fn_116_2E00(void*, short);
void* fn_116_2E5C(void*, short);
void* fn_116_2EB8(void*, short);
void* fn_116_160A8(void*, short);
void* fn_116_2FC4(void*, short);
void* fn_116_3020(void*, short);
void* fn_116_16140(void*, short);
void* fn_116_5498(void*, short);
void* fn_116_16D1C(void*, short);
void* fn_116_16D94(void*, short);
void* fn_116_61BC(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_6298(void*, short);
void* fn_116_630C(void*, short);
void* fn_116_63E8(void*, short);
void* fn_116_6444(void*, short);
void* fn_116_64B0(void*, short);
void* fn_116_655C(void*, short);
void* fn_116_65D0(void*, short);
void* fn_116_662C(void*, short);
void* fn_116_6688(void*, short);
void* fn_116_66E4(void*, short);
void* fn_116_6740(void*, short);
void* fn_116_67B4(void*, short);
void* fn_116_6820(void*, short);
void* fn_116_68B0(void*, short);
void* fn_116_16E8C(void*, short);
void* fn_116_69C4(void*, short);
void* fn_116_6A48(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_116_16F10(void*, short);
void* fn_116_6F40(void*, short);
void* fn_116_7014(void*, short);
void* fn_116_708C(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_116_70E8(void*, short);
}

extern "C" void* fn_116_15E08(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_2B58(members + 0x14444, memberDeleting);
        fn_116_2BB4(members + 0x14408, memberDeleting);
        fn_116_2C10(members + 0x143A0, memberDeleting);
        fn_116_2C6C(members + 0x14354, memberDeleting);
        fn_116_2CC8(members + 0x14200, memberDeleting);
        fn_116_2D24(members + 0x140F0, memberDeleting);
        fn_116_2E00(members + 0x140A8, memberDeleting);
        fn_116_2E5C(members + 0x14028, memberDeleting);
        fn_116_2EB8(members + 0x13F64, memberDeleting);
        fn_116_160A8(members + 0x13BCC, memberDeleting);
        fn_116_2FC4(members + 0x13B9C, memberDeleting);
        fn_116_3020(members + 0x139F8, memberDeleting);
        fn_116_16140(members + 0x573C, memberDeleting);
        fn_116_5498(members + 0x5558, memberDeleting);
        fn_116_16D1C(members + 0x5250, memberDeleting);
        fn_116_16D94(members + 0x43D4, memberDeleting);
        fn_116_61BC(members + 0x42E0, memberDeleting);
        fn_116_3EBC(members + 0x42AC, memberDeleting);
        fn_116_6298(members + 0x4238, memberDeleting);
        fn_116_630C(members + 0x3B14, memberDeleting);
        fn_116_63E8(members + 0x3AE4, memberDeleting);
        fn_116_6444(members + 0x394C, memberDeleting);
        fn_116_64B0(members + 0x38DC, memberDeleting);
        fn_116_655C(members + 0x3844, memberDeleting);
        fn_116_65D0(members + 0x380C, memberDeleting);
        fn_116_662C(members + 0x37E8, memberDeleting);
        fn_116_6688(members + 0x37B4, memberDeleting);
        fn_116_66E4(members + 0x3750, memberDeleting);
        fn_116_6740(members + 0x35A0, memberDeleting);
        fn_116_67B4(members + 0x333C, memberDeleting);
        fn_116_6820(members + 0x28D0, memberDeleting);
        fn_116_68B0(members + 0x26B8, memberDeleting);
        fn_116_16E8C(members + 0x209C, memberDeleting);
        fn_116_69C4(members + 0x19E0, memberDeleting);
        fn_116_6A48(members + 0x196C, memberDeleting);
        fn_116_4190(members + 0x1930, memberDeleting);
        fn_116_41EC(members + 0x1888, memberDeleting);
        fn_116_4258(members + 0x17D4, memberDeleting);
        fn_116_16F10(members + 0x1440, memberDeleting);
        fn_116_6F40(members + 0x1180, memberDeleting);
        fn_116_7014(members + 0x115C, memberDeleting);
        fn_116_708C(members + 0xAC8, memberDeleting);
        fn_116_430C(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_116_70E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}