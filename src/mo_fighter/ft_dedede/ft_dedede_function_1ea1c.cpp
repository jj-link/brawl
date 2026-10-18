#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_474C(void*, short);
void* fn_117_47D0(void*, short);
void* fn_117_1E9C0(void*, short);
void* fn_117_6240(void*, short);
void* fn_117_1E960(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_117_1EA1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_474C(members + 0x21C, memberDeleting);
        fn_117_47D0(members + 0x208, memberDeleting);
        fn_117_1E9C0(members + 0x194, memberDeleting);
        fn_117_6240(members + 0xD0, memberDeleting);
        fn_117_1E960(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
