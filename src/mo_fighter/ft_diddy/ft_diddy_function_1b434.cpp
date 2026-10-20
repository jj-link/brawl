#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_115_1AA44(void* object, short baseDeleting);
void* fn_27_1DBB60(void*, short);
void* fn_115_1B3C4(void* object, short deleting);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void*);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_115_1B434(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_1AA44(members + 0x1F50, memberDeleting);
        fn_27_1DBB60(members + 0x1F18, memberDeleting);
        fn_115_1B3C4(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
