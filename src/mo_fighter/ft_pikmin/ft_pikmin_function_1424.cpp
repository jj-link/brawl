#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_113_D68(void*, short);
void* fn_113_E04(void*, short);
void* fn_113_E44(void*, short);
void* fn_113_14BC(void*, short);
void* fn_27_1A5CCC(void*, short);
}

extern "C" void* fn_113_1424(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_D68(members + 0x9C4, memberDeleting);
        fn_113_E04(members + 0x9A8, memberDeleting);
        fn_113_E44(members + 0x8FC, memberDeleting);
        fn_113_14BC(members + 0x47C, memberDeleting);
        if (object != 0) {
            fn_27_1A5CCC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
