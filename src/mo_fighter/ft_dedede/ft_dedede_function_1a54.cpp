void operator delete(void*);

extern "C" {
void* fn_117_1B0C(void*, short);
void* fn_117_1BCC(void*, short);
void* fn_117_1C28(void*, short);
void* fn_117_1C84(void*, short);
void* fn_117_1CE0(void*, short);
void* fn_117_1D3C(void*, short);
void* fn_117_1D98(void*, short);
void* fn_117_1DF4(void*, short);
}

// Guarded embedded-member cleanup for the Dedede fighter module: destroys the
// seven member objects in reverse declaration order, runs the base destructor
// layer, and deletes the storage when requested.
extern "C" void* fn_117_1A54(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_1B0C(static_cast<unsigned char*>(object) + 0x84, memberDeleting);
        fn_117_1BCC(static_cast<unsigned char*>(object) + 0x70, memberDeleting);
        fn_117_1C28(static_cast<unsigned char*>(object) + 0x5C, memberDeleting);
        fn_117_1C84(static_cast<unsigned char*>(object) + 0x48, memberDeleting);
        fn_117_1CE0(static_cast<unsigned char*>(object) + 0x34, memberDeleting);
        fn_117_1D3C(static_cast<unsigned char*>(object) + 0x20, memberDeleting);
        fn_117_1D98(static_cast<unsigned char*>(object) + 0x08, memberDeleting);
        fn_117_1DF4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
