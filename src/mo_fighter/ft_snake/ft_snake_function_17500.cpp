#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_122_6B18(void*, short);
void fn_122_17580(void*, short);
void fn_27_1998BC(void*, short);
}

extern "C" void* fn_122_17500(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_6B18(members + 0xB8, memberDeleting);
        fn_122_17580(members + 0x98, memberDeleting);
        if (object != 0) {
            fn_27_1998BC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
