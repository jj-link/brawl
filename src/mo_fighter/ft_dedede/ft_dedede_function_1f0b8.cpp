#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_14CC8(void*, short);
void* fn_117_1F02C(void*, short);
void* fn_117_1EFA0(void*, short);
void* fn_117_1EF14(void*, short);
void* fn_117_1EE88(void*, short);
}

extern "C" void* fn_117_1F0B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_14CC8(members + 0x4B0, memberDeleting);
        fn_117_1F02C(members + 0x384, memberDeleting);
        fn_117_1EFA0(members + 0x258, memberDeleting);
        fn_117_1EF14(members + 0x12C, memberDeleting);
        fn_117_1EE88(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
