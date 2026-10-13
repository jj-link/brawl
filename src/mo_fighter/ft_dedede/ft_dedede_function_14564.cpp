void operator delete(void*);

extern "C" {
void* fn_117_474C(void*, short);
void* fn_117_47D0(void*, short);
void* fn_117_14508(void*, short);
void* fn_117_14490(void*, short);
void* fn_117_14374(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_117_14564(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_474C(members + 0x110, memberDeleting);
        fn_117_47D0(members + 0xFC, memberDeleting);
        fn_117_14508(members + 0xEC, memberDeleting);
        fn_117_14490(members + 0x48, memberDeleting);
        fn_117_14374(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
