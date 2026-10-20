#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_113_D68(void*, short);
void* fn_113_E04(void*, short);
void* fn_113_E44(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_113_1280(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_D68(members + 0xDC, memberDeleting);
        fn_113_E04(members + 0xC0, memberDeleting);
        fn_113_E44(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
