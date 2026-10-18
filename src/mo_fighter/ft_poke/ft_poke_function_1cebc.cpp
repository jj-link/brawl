#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_19C8(void*, short);
void* fn_116_1DA8(void*, short);
void* fn_116_1E44(void*, short);
void* fn_116_1CF5C(void*, short);
void fn_27_125E20(void*, short);
}

extern "C" void* fn_116_1CEBC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_19C8(members + 0x1105C, memberDeleting);
        fn_116_1DA8(members + 0x10BA4, memberDeleting);
        fn_116_1E44(members + 0x10B68, memberDeleting);
        fn_116_1CF5C(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
