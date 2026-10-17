extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_117_6064(void*, short);
void* fn_117_60D0(void*, short);
void* fn_117_612C(void*, short);
void* fn_117_6188(void*, short);
void* fn_117_61E4(void*, short);
void* fn_117_6240(void*, short);
}
void operator delete(void*);

// Destroy the module-holder aggregate embedded at fighter storage +0x1440.
// Each member and base destructor receives the non-deleting flag.
// A positive deleting flag releases this aggregate's own storage;
// the enclosing fighter object's storage is not the pointer passed here.
extern "C" void* fn_117_5FB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(members + 0x224, memberDeleting);
        fn_117_6064(members + 0x1E8, memberDeleting);
        fn_27_21038(members + 0x1D8, memberDeleting);
        fn_117_60D0(members + 0x1B8, memberDeleting);
        fn_117_612C(members + 0x198, memberDeleting);
        fn_117_6188(members + 0x160, memberDeleting);
        fn_117_61E4(members + 0xC4, memberDeleting);
        fn_117_6240(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
