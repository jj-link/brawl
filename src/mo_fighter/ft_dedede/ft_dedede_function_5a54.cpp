#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_4E038(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CD4A4(void*, short);
}

extern "C" void* fn_117_5A54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_4E038(members + 0xF0, memberDeleting);
        fn_27_4CAA0(members + 0x6C, memberDeleting);
        fn_27_CD4A4(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
