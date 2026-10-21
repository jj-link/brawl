#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_726C(void*, short);
void* fn_116_722C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_1928(void*, short);
}

extern "C" void* fn_116_A34C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_726C(members + 0x17FBC, memberDeleting);
        fn_116_722C(members + 0x17FA4, memberDeleting);
        fn_27_C74E8(members + 0x17F90, memberDeleting);
        fn_116_1928(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
