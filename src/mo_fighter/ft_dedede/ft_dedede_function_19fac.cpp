#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_14CC8(void*, short);
void* fn_117_19F20(void*, short);
void* fn_117_19E94(void*, short);
void* fn_117_19E08(void*, short);
void* fn_117_19D7C(void*, short);
}

extern "C" void* fn_117_19FAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_14CC8(members + 0x4B0, memberDeleting);
        fn_117_19F20(members + 0x384, memberDeleting);
        fn_117_19E94(members + 0x258, memberDeleting);
        fn_117_19E08(members + 0x12C, memberDeleting);
        fn_117_19D7C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
