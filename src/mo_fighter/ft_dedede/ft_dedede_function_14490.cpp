#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_4904(void*, short);
void* fn_117_14434(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_117_14490(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_4904(members + 0x8C, memberDeleting);
        fn_117_14434(members + 0x20, memberDeleting);
        fn_27_CD934(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
