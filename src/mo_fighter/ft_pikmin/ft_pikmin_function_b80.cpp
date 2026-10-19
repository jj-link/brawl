#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_113_C04(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_113_1518(void*, short);
}

extern "C" void* fn_113_B80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_C04(members + 0x1E010, memberDeleting);
        fn_27_C74E8(members + 0x1E000, memberDeleting);
        fn_113_1518(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
