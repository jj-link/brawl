#pragma force_active on
extern "C" {
void* fn_102_10E64(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_102_11490(void*, short);
}

void operator delete(void*);

extern "C" void* fn_102_10DE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_10E64(members + 0x121DC, memberDeleting);
        fn_27_C74E8(members + 0x121CC, memberDeleting);
        fn_102_11490(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
