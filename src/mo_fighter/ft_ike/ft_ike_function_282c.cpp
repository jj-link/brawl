#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_119_21CC(void*, short);
void* fn_119_2268(void*, short);
void* fn_119_22A8(void*, short);
void* fn_119_28C4(void*, short);
void fn_27_1A66F4(void*, short);
}

extern "C" void* fn_119_282C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_119_21CC(members + 0xA1C, memberDeleting);
        fn_119_2268(members + 0xA00, memberDeleting);
        fn_119_22A8(members + 0x954, memberDeleting);
        fn_119_28C4(members + 0x4A8, memberDeleting);
        if (object != 0) {
            fn_27_1A66F4(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
