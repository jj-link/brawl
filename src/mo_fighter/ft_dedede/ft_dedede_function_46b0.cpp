#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_474C(void*, short);
void* fn_117_47D0(void*, short);
void* fn_117_4830(void*, short);
void* fn_117_488C(void*, short);
void* fn_117_5344(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_117_46B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_474C(members + 0xE5C, memberDeleting);
        fn_117_47D0(members + 0xE48, memberDeleting);
        fn_117_4830(members + 0x954, memberDeleting);
        fn_117_488C(members + 0xE0, memberDeleting);
        fn_117_5344(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
