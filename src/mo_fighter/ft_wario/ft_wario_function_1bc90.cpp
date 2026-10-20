#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_110_1BD18(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_110_1BD74(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_110_1BC90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_1BD18(members + 0x202C, memberDeleting);
        fn_27_1DBB60(members + 0x1FF4, memberDeleting);
        fn_110_1BD74(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
