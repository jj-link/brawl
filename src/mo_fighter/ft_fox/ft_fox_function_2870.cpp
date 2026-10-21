#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_97_2210(void*, short);
void* fn_97_22AC(void*, short);
void* fn_97_22EC(void*, short);
void* fn_97_2908(void*, short);
void fn_27_1A60DC(void*, short);
}

extern "C" void* fn_97_2870(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_97_2210(members + 0x9E4, memberDeleting);
        fn_97_22AC(members + 0x9C8, memberDeleting);
        fn_97_22EC(members + 0x91C, memberDeleting);
        fn_97_2908(members + 0x48C, memberDeleting);
        if (object != 0) {
            fn_27_1A60DC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
