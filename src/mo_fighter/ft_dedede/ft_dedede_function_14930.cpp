void operator delete(void*);

extern "C" {
void* fn_117_148D4(void*, short);
void* fn_117_14878(void*, short);
void* fn_117_147EC(void*, short);
void* fn_117_1478C(void*, short);
void* fn_117_14714(void*, short);
void* fn_117_14564(void*, short);
void* fn_117_14308(void*, short);
void* fn_117_54DC(void*, short);
void* fn_117_1424C(void*, short);
void* fn_117_141E0(void*, short);
void* fn_117_14174(void*, short);
void* fn_117_140D4(void*, short);
void* fn_117_14078(void*, short);
void* fn_117_13FF4(void*, short);
void* fn_117_13F30(void*, short);
void* fn_117_5E74(void*, short);
void* fn_117_5F3C(void*, short);
void* fn_117_13DC4(void*, short);
void* fn_117_13C24(void*, short);
void* fn_117_13BC4(void*, short);
void* fn_117_655C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_117_139FC(void*, short);
}

extern "C" void* fn_117_14930(void* object, short deleting) {
    if (object != 0) {
        // Embedded modules are destroyed in reverse construction order;
        // only the aggregate's deleting form releases its backing storage.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_148D4(members + 0x1790, memberDeleting);
        fn_117_14878(members + 0x1778, memberDeleting);
        fn_117_147EC(members + 0x15DC, memberDeleting);
        fn_117_1478C(members + 0x157C, memberDeleting);
        fn_117_14714(members + 0x14C8, memberDeleting);
        fn_117_14564(members + 0x1308, memberDeleting);
        fn_117_14308(members + 0x1264, memberDeleting);
        fn_117_54DC(members + 0x1230, memberDeleting);
        fn_117_1424C(members + 0x1218, memberDeleting);
        fn_117_141E0(members + 0x10B4, memberDeleting);
        fn_117_14174(members + 0x104C, memberDeleting);
        fn_117_140D4(members + 0x1040, memberDeleting);
        fn_117_14078(members + 0x1018, memberDeleting);
        fn_117_13FF4(members + 0x0E48, memberDeleting);
        fn_117_13F30(members + 0x0DE4, memberDeleting);
        fn_117_5E74(members + 0x0DA8, memberDeleting);
        fn_117_5F3C(members + 0x0CF0, memberDeleting);
        fn_117_13DC4(members + 0x0AE4, memberDeleting);
        fn_117_13C24(members + 0x0904, memberDeleting);
        fn_117_13BC4(members + 0x08F0, memberDeleting);
        fn_117_655C(members + 0x08D8, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x07F8, memberDeleting);
        fn_117_139FC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
