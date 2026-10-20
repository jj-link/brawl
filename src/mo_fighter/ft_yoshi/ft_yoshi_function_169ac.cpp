#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_3808(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_95_16A34(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_95_169AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_3808(members + 0x1F58, memberDeleting);
        fn_27_1DBB60(members + 0x1F20, memberDeleting);
        fn_95_16A34(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
