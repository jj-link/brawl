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
void* fn_116_3170(void*, short);
void* fn_116_5498(void*, short);
void* fn_116_54F8(void*, short);
void* fn_116_564C(void*, short);
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
void* fn_116_6940(void*, short);
void* fn_116_69C4(void*, short);
void* fn_116_6A48(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_116_6B7C(void*, short);
void* fn_116_6F40(void*, short);
void* fn_116_7014(void*, short);
void* fn_116_708C(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_116_70E8(void*, short);
}

extern "C" void* fn_116_28B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_2B58(members + 0x16124, memberDeleting);
        fn_116_2BB4(members + 0x160E8, memberDeleting);
        fn_116_2C10(members + 0x16080, memberDeleting);
        fn_116_2C6C(members + 0x16034, memberDeleting);
        fn_116_2CC8(members + 0x15EE0, memberDeleting);
        fn_116_2D24(members + 0x15DD0, memberDeleting);
        fn_116_2E00(members + 0x15D88, memberDeleting);
        fn_116_2E5C(members + 0x15D08, memberDeleting);
        fn_116_2EB8(members + 0x15C44, memberDeleting);
        fn_116_2F2C(members + 0x158D0, memberDeleting);
        fn_116_2FC4(members + 0x158A0, memberDeleting);
        fn_116_3020(members + 0x156FC, memberDeleting);
        fn_116_3170(members + 0x590C, memberDeleting);
        fn_116_5498(members + 0x5728, memberDeleting);
        fn_116_54F8(members + 0x5420, memberDeleting);
        fn_116_564C(members + 0x45BC, memberDeleting);
        fn_116_61BC(members + 0x44C8, memberDeleting);
        fn_116_3EBC(members + 0x4494, memberDeleting);
        fn_116_6298(members + 0x4420, memberDeleting);
        fn_116_630C(members + 0x3CFC, memberDeleting);
        fn_116_63E8(members + 0x3CCC, memberDeleting);
        fn_116_6444(members + 0x3B34, memberDeleting);
        fn_116_64B0(members + 0x3AC4, memberDeleting);
        fn_116_655C(members + 0x3A2C, memberDeleting);
        fn_116_65D0(members + 0x39F4, memberDeleting);
        fn_116_662C(members + 0x39D0, memberDeleting);
        fn_116_6688(members + 0x399C, memberDeleting);
        fn_116_66E4(members + 0x3938, memberDeleting);
        fn_116_6740(members + 0x3788, memberDeleting);
        fn_116_67B4(members + 0x3524, memberDeleting);
        fn_116_6820(members + 0x2AB8, memberDeleting);
        fn_116_68B0(members + 0x28A0, memberDeleting);
        fn_116_6940(members + 0x20E4, memberDeleting);
        fn_116_69C4(members + 0x1A28, memberDeleting);
        fn_116_6A48(members + 0x19B4, memberDeleting);
        fn_116_4190(members + 0x1978, memberDeleting);
        fn_116_41EC(members + 0x18D0, memberDeleting);
        fn_116_4258(members + 0x181C, memberDeleting);
        fn_116_6B7C(members + 0x1440, memberDeleting);
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