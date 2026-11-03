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
void* fn_116_2F2C(void*, short);
void* fn_116_2FC4(void*, short);
void* fn_116_3020(void*, short);
void* fn_116_1D44C(void*, short);
void* fn_116_5498(void*, short);
void* fn_116_54F8(void*, short);
void* fn_116_1E84C(void*, short);
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
void* fn_116_1E944(void*, short);
void* fn_116_6820(void*, short);
void* fn_116_68B0(void*, short);
void* fn_116_1E9B0(void*, short);
void* fn_116_69C4(void*, short);
void* fn_116_6A48(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_116_1EA34(void*, short);
void* fn_116_6F40(void*, short);
void* fn_116_7014(void*, short);
void* fn_116_708C(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_116_70E8(void*, short);
}

extern "C" void* fn_116_1D1AC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_116_2B58((storage + 0x10000) - 0xD78, destroy);
        fn_116_2BB4((storage + 0x10000) - 0xDB4, destroy);
        fn_116_2C10((storage + 0x10000) - 0xE1C, destroy);
        fn_116_2C6C((storage + 0x10000) - 0xE68, destroy);
        fn_116_2CC8((storage + 0x10000) - 0xFBC, destroy);
        fn_116_2D24((storage + 0x10000) - 0x10CC, destroy);
        fn_116_2E00((storage + 0x10000) - 0x1114, destroy);
        fn_116_2E5C((storage + 0x10000) - 0x1194, destroy);
        fn_116_2EB8((storage + 0x10000) - 0x1258, destroy);
        fn_116_2F2C((storage + 0x10000) - 0x15CC, destroy);
        fn_116_2FC4((storage + 0x10000) - 0x15FC, destroy);
        fn_116_3020((storage + 0x10000) - 0x17A0, destroy);
        fn_116_1D44C(storage + 0x55E8, destroy);
        fn_116_5498(storage + 0x5404, destroy);
        fn_116_54F8(storage + 0x50FC, destroy);
        fn_116_1E84C(storage + 0x4290, destroy);
        fn_116_61BC(storage + 0x419C, destroy);
        fn_116_3EBC(storage + 0x4168, destroy);
        fn_116_6298(storage + 0x40F4, destroy);
        fn_116_630C(storage + 0x39D0, destroy);
        fn_116_63E8(storage + 0x39A0, destroy);
        fn_116_6444(storage + 0x3808, destroy);
        fn_116_64B0(storage + 0x3798, destroy);
        fn_116_655C(storage + 0x3700, destroy);
        fn_116_65D0(storage + 0x36C8, destroy);
        fn_116_662C(storage + 0x36A4, destroy);
        fn_116_6688(storage + 0x3670, destroy);
        fn_116_66E4(storage + 0x360C, destroy);
        fn_116_6740(storage + 0x345C, destroy);
        fn_116_1E944(storage + 0x319C, destroy);
        fn_116_6820(storage + 0x2730, destroy);
        fn_116_68B0(storage + 0x2518, destroy);
        fn_116_1E9B0(storage + 0x209C, destroy);
        fn_116_69C4(storage + 0x19E0, destroy);
        fn_116_6A48(storage + 0x196C, destroy);
        fn_116_4190(storage + 0x1930, destroy);
        fn_116_41EC(storage + 0x1888, destroy);
        fn_116_4258(storage + 0x17D4, destroy);
        fn_116_1EA34(storage + 0x1440, destroy);
        fn_116_6F40(storage + 0x1180, destroy);
        fn_116_7014(storage + 0x115C, destroy);
        fn_116_708C(storage + 0xAC8, destroy);
        fn_116_430C(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_116_70E8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}