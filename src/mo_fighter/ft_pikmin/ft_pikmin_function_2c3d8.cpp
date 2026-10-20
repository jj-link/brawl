#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_113_2C460(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_113_2C4BC(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_113_2C3D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_2C460(members + 0x1EBC, memberDeleting);
        fn_27_1DBB60(members + 0x1E84, memberDeleting);
        fn_113_2C4BC(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
