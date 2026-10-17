void operator delete(void*);
extern "C" {
void* fn_101_1CF4(void*, short);
void* fn_101_1DB4(void*, short);
void* fn_101_1E10(void*, short);
void* fn_101_1E6C(void*, short);
void* fn_101_1EC8(void*, short);
void* fn_101_1F24(void*, short);
void* fn_101_1F80(void*, short);
void* fn_101_1FDC(void*, short);
}

// Complete-object destructor for the embedded aggregate at fighter work area
// offset 0x4AD68 (fn_101_1B9C computes the member base and forwards the
// inherited deleting flag). Members are destroyed in reverse declaration
// order; the base sub-object cleanup fn_101_1FDC is invoked with a zero
// deleting flag, and the storage is freed only when the caller's flag is
// positive.
extern "C" void* fn_101_1C3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_1CF4(members + 0x84, memberDeleting);
        fn_101_1DB4(members + 0x70, memberDeleting);
        fn_101_1E10(members + 0x5C, memberDeleting);
        fn_101_1E6C(members + 0x48, memberDeleting);
        fn_101_1EC8(members + 0x34, memberDeleting);
        fn_101_1F24(members + 0x20, memberDeleting);
        fn_101_1F80(members + 0x8, memberDeleting);
        fn_101_1FDC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
