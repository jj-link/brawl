#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_689B0(void*, short);
void* fn_27_1985B4(void*, short);
}

extern "C" void* fn_117_57FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_689B0(members + 0x7C, memberDeleting);
        if (object != 0) {
            fn_27_1985B4(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
