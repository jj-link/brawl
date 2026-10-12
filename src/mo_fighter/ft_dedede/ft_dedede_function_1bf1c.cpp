void operator delete(void*);

extern "C" {
void* fn_117_1BEC0(void*, short);
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
void* fn_117_5ED0(void*, short);
void* fn_117_5F3C(void*, short);
void* fn_117_13DC4(void*, short);
void* fn_117_13C24(void*, short);
void* fn_117_19970(void*, short);
void* fn_117_13BC4(void*, short);
void* fn_117_655C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_117_139FC(void*, short);
}

extern "C" void* fn_117_1BF1C(void* object, short deleting) {
    if (object != 0) {
        // Embedded modules are destroyed in reverse construction order;
        // only the aggregate's deleting form releases their backing storage.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_1BEC0(members + 0x18A0, memberDeleting);
        fn_117_148D4(members + 0x1860, memberDeleting);
        fn_117_14878(members + 0x1848, memberDeleting);
        fn_117_147EC(members + 0x16AC, memberDeleting);
        fn_117_1478C(members + 0x164C, memberDeleting);
        fn_117_14714(members + 0x1598, memberDeleting);
        fn_117_14564(members + 0x13D8, memberDeleting);
        fn_117_14308(members + 0x1334, memberDeleting);
        fn_117_54DC(members + 0x1300, memberDeleting);
        fn_117_1424C(members + 0x12E8, memberDeleting);
        fn_117_141E0(members + 0x1184, memberDeleting);
        fn_117_14174(members + 0x111C, memberDeleting);
        fn_117_140D4(members + 0x1110, memberDeleting);
        fn_117_14078(members + 0x10E8, memberDeleting);
        fn_117_13FF4(members + 0x0F18, memberDeleting);
        fn_117_13F30(members + 0x0EB4, memberDeleting);
        fn_117_5E74(members + 0x0E78, memberDeleting);
        fn_117_5ED0(members + 0x0DD0, memberDeleting);
        fn_117_5F3C(members + 0x0D1C, memberDeleting);
        fn_117_13DC4(members + 0x0B10, memberDeleting);
        fn_117_13C24(members + 0x0930, memberDeleting);
        fn_117_19970(members + 0x0900, memberDeleting);
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
