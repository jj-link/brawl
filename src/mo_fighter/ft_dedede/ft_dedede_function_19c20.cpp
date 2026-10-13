void operator delete(void*);
extern "C" {
void* fn_117_148D4(void*, short);
void* fn_117_14878(void*, short);
void* fn_117_19BC4(void*, short);
void* fn_117_2E98(void*, short);
void* fn_117_147EC(void*, short);
void* fn_117_1478C(void*, short);
void* fn_117_19B28(void*, short);
void* fn_117_14308(void*, short);
void* fn_117_54DC(void*, short);
void* fn_117_1424C(void*, short);
void* fn_117_141E0(void*, short);
void* fn_117_14174(void*, short);
void* fn_117_140D4(void*, short);
void* fn_117_14078(void*, short);
void* fn_117_13F30(void*, short);
void* fn_117_199E8(void*, short);
void* fn_117_13C24(void*, short);
void* fn_117_19970(void*, short);
void* fn_117_13BC4(void*, short);
void* fn_117_655C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_117_197E8(void*, short);
}

// Destroy the embedded module group in reverse construction order.  Only the
// outer object's deleting flag controls release of its allocation.
extern "C" void* fn_117_19C20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_148D4(members + 0x1680, memberDeleting);
        fn_117_14878(members + 0x1668, memberDeleting);
        fn_117_19BC4(members + 0x1510, memberDeleting);
        fn_117_2E98(members + 0x14C4, memberDeleting);
        fn_117_147EC(members + 0x132C, memberDeleting);
        fn_117_1478C(members + 0x12CC, memberDeleting);
        fn_117_19B28(members + 0x10C8, memberDeleting);
        fn_117_14308(members + 0x1024, memberDeleting);
        fn_117_54DC(members + 0xFF0, memberDeleting);
        fn_117_1424C(members + 0xFD8, memberDeleting);
        fn_117_141E0(members + 0xE74, memberDeleting);
        fn_117_14174(members + 0xE0C, memberDeleting);
        fn_117_140D4(members + 0xE00, memberDeleting);
        fn_117_14078(members + 0xDD8, memberDeleting);
        fn_117_13F30(members + 0xD68, memberDeleting);
        fn_117_199E8(members + 0xB1C, memberDeleting);
        fn_117_13C24(members + 0x93C, memberDeleting);
        fn_117_19970(members + 0x90C, memberDeleting);
        fn_117_13BC4(members + 0x8FC, memberDeleting);
        fn_117_655C(members + 0x8E4, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x804, memberDeleting);
        fn_117_197E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
