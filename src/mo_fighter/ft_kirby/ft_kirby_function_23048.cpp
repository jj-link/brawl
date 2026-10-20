#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_8460(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_96_230D0(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_96_23048(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_96_8460(members + 0x1F5C, memberDeleting);
        fn_27_1DBB60(members + 0x1F24, memberDeleting);
        fn_96_230D0(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
