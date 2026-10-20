#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_23D8(void*, short);
void* fn_101_2474(void*, short);
void* fn_101_24B4(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_101_25D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_23D8(members + 0xDC, memberDeleting);
        fn_101_2474(members + 0xC0, memberDeleting);
        fn_101_24B4(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
