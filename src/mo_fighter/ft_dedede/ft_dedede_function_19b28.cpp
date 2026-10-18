#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_474C(void*, short);
void* fn_117_47D0(void*, short);
void* fn_117_19ACC(void*, short);
void* fn_117_14490(void*, short);
void* fn_117_19A6C(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_117_19B28(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_474C(members + 0x154, memberDeleting);
        fn_117_47D0(members + 0x140, memberDeleting);
        fn_117_19ACC(members + 0x10C, memberDeleting);
        fn_117_14490(members + 0x68, memberDeleting);
        fn_117_19A6C(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
