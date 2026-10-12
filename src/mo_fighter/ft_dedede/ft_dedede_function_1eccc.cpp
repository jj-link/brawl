void operator delete(void*);
extern "C" {
void* fn_117_1BEC0(void*, short);
void* fn_117_148D4(void*, short);
void* fn_117_14878(void*, short);
void* fn_117_1EC48(void*, short);
void* fn_117_147EC(void*, short);
void* fn_117_1EBD0(void*, short);
void* fn_117_1478C(void*, short);
void* fn_117_1EAB8(void*, short);
void* fn_117_1EA1C(void*, short);
void* fn_117_14308(void*, short);
void* fn_117_54DC(void*, short);
void* fn_117_1E904(void*, short);
void* fn_117_141E0(void*, short);
void* fn_117_14174(void*, short);
void* fn_117_140D4(void*, short);
void* fn_117_14078(void*, short);
void* fn_117_1E890(void*, short);
void* fn_117_1E80C(void*, short);
void* fn_117_13FF4(void*, short);
void* fn_117_13F30(void*, short);
void* fn_117_5E74(void*, short);
void* fn_117_5ED0(void*, short);
void* fn_117_5F3C(void*, short);
void* fn_117_1E794(void*, short);
void* fn_117_1E728(void*, short);
void* fn_117_19970(void*, short);
void* fn_117_13BC4(void*, short);
void* fn_117_655C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_117_139FC(void*, short);
}

// Destroy the embedded module group in reverse construction order.  The
// deleting flag belongs to the outer object, not its embedded members.
extern "C" void* fn_117_1ECCC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_1BEC0(members + 0x1FA8, memberDeleting);
        fn_117_148D4(members + 0x1F68, memberDeleting);
        fn_117_14878(members + 0x1F50, memberDeleting);
        fn_117_1EC48(members + 0x1E18, memberDeleting);
        fn_117_147EC(members + 0x1C84, memberDeleting);
        fn_117_1EBD0(members + 0x1C18, memberDeleting);
        fn_117_1478C(members + 0x1BBC, memberDeleting);
        fn_117_1EAB8(members + 0x19AC, memberDeleting);
        fn_117_1EA1C(members + 0x16E0, memberDeleting);
        fn_117_14308(members + 0x163C, memberDeleting);
        fn_117_54DC(members + 0x1608, memberDeleting);
        fn_117_1E904(members + 0x15D4, memberDeleting);
        fn_117_141E0(members + 0x1470, memberDeleting);
        fn_117_14174(members + 0x1408, memberDeleting);
        fn_117_140D4(members + 0x13FC, memberDeleting);
        fn_117_14078(members + 0x13D4, memberDeleting);
        fn_117_1E890(members + 0x1220, memberDeleting);
        fn_117_1E80C(members + 0x1074, memberDeleting);
        fn_117_13FF4(members + 0xEB0, memberDeleting);
        fn_117_13F30(members + 0xE4C, memberDeleting);
        fn_117_5E74(members + 0xE10, memberDeleting);
        fn_117_5ED0(members + 0xD68, memberDeleting);
        fn_117_5F3C(members + 0xCB4, memberDeleting);
        fn_117_1E794(members + 0xAA8, memberDeleting);
        fn_117_1E728(members + 0x930, memberDeleting);
        fn_117_19970(members + 0x900, memberDeleting);
        fn_117_13BC4(members + 0x8F0, memberDeleting);
        fn_117_655C(members + 0x8D8, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x7F8, memberDeleting);
        fn_117_139FC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
