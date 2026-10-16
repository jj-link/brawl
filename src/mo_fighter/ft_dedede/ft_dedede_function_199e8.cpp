extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_117_6188(void*, short);
void* fn_117_13D4C(void*, short);
}
void operator delete(void*);

// Destroy the embedded module group stored at offset 0xB1C of the fighter
// module holder.  Only the outer object's deleting flag controls release of
// its allocation.
extern "C" void* fn_117_199E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(members + 0xD8, memberDeleting);
        fn_27_21038(members + 0xC4, memberDeleting);
        fn_117_6188(members + 0x88, memberDeleting);
        fn_117_13D4C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
