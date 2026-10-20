#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_94_15310(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_94_1F458(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_94_1F3D0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_15310(members + 0x1560, memberDeleting);
        fn_27_1DBB60(members + 0x1528, memberDeleting);
        fn_94_1F458(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
