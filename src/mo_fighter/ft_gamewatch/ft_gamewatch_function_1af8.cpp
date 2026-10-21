#pragma force_active on
extern "C" {
void* fn_107_1BB0(void*, short);
void* fn_107_1C70(void*, short);
void* fn_107_1CCC(void*, short);
void* fn_107_1D28(void*, short);
void* fn_107_1D84(void*, short);
void* fn_107_1DE0(void*, short);
void* fn_107_1E3C(void*, short);
void* fn_107_1E98(void*, short);
}

void operator delete(void*);

extern "C" void* fn_107_1AF8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_1BB0(members + 0x84, memberDeleting);
        fn_107_1C70(members + 0x70, memberDeleting);
        fn_107_1CCC(members + 0x5C, memberDeleting);
        fn_107_1D28(members + 0x48, memberDeleting);
        fn_107_1D84(members + 0x34, memberDeleting);
        fn_107_1DE0(members + 0x20, memberDeleting);
        fn_107_1E3C(members + 0x08, memberDeleting);
        fn_107_1E98(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
