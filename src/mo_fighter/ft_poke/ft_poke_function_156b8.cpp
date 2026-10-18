#pragma force_active on
extern "C" {
void fn_116_19C8(void*, short);
void fn_116_1DA8(void*, short);
void fn_116_1E44(void*, short);
void fn_116_15758(void*, short);
void fn_27_125E20(void*, short);
}

extern "C" void* fn_116_156B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_19C8(members + 0x16238, memberDeleting);
        fn_116_1DA8(members + 0x15d80, memberDeleting);
        fn_116_1E44(members + 0x15d44, memberDeleting);
        fn_116_15758(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
