#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_121_1B74(void*, short);
void* fn_121_1C18(void*, short);
void* fn_121_1C74(void*, short);
void* fn_121_1CD0(void*, short);
void* fn_121_1D2C(void*, short);
void* fn_121_1D88(void*, short);
void* fn_121_1DE4(void*, short);
void* fn_121_1E40(void*, short);
}

extern "C" void* fn_121_1E9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_121_1E40(members + 0x84, memberDeleting);
        fn_121_1DE4(members + 0x70, memberDeleting);
        fn_121_1D88(members + 0x5C, memberDeleting);
        fn_121_1D2C(members + 0x48, memberDeleting);
        fn_121_1CD0(members + 0x34, memberDeleting);
        fn_121_1C74(members + 0x20, memberDeleting);
        fn_121_1C18(members + 0x08, memberDeleting);
        fn_121_1B74(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
