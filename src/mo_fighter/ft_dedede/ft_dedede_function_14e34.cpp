void operator delete(void*);

extern "C" {
void* fn_117_139A0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_117_14DC4(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_117_14E34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_139A0(members + 0x1E88, memberDeleting);
        fn_27_1DBB60(members + 0x1E50, memberDeleting);
        fn_117_14DC4(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
