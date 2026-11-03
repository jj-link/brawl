#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_113_6804(void* ptr, short flag);
void* fn_113_6770(void* ptr, short count);
void* fn_113_671C(void* ptr, short size);
void* fn_113_66C8(void* ptr, short count);
void* fn_113_663C(void* ptr, short count);
void* fn_113_65B0(void* ptr, short count);
void* fn_113_655C(void* ptr, short count);
void* fn_113_64D0(void* ptr, short count);
void* fn_113_6434(void* ptr, short count);
void* fn_113_63E0(void* ptr, short count);
void* fn_113_638C(void* ptr, short count);
void* fn_27_1A036C(void* ptr, short count);
void* fn_113_6300(void* ptr, short count);
void* fn_113_4D8(void* object, short deleting);
}

extern "C" void* fn_113_C6B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_6804(members + 0x20128, memberDeleting);
        fn_113_6770(members + 0x20120, memberDeleting);
        fn_113_671C(members + 0x20118, memberDeleting);
        fn_113_66C8(members + 0x20110, memberDeleting);
        fn_113_663C(members + 0x20108, memberDeleting);
        fn_113_65B0(members + 0x20100, memberDeleting);
        fn_113_655C(members + 0x200F8, memberDeleting);
        fn_113_64D0(members + 0x200F0, memberDeleting);
        fn_113_6434(members + 0x200E8, memberDeleting);
        fn_113_63E0(members + 0x200E0, memberDeleting);
        fn_113_638C(members + 0x200D8, memberDeleting);
        fn_27_1A036C(members + 0x1FE8C, memberDeleting);
        fn_113_6300(members + 0x1FD08, memberDeleting);
        fn_113_4D8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
