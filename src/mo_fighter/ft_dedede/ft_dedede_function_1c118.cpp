#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_139A0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_117_1C0A8(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Guarded embedded-member cleanup for the Dedede fighter module: destroys the
// three member objects in reverse declaration order, runs the base destructor
// layer, and deletes the storage when requested.
extern "C" void* fn_117_1C118(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_139A0(members + 0x1F70, memberDeleting);
        fn_27_1DBB60(members + 0x1F38, memberDeleting);
        fn_117_1C0A8(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
