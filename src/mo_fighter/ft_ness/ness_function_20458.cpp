#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_3BA8(void*, short);
void* fn_101_57F0(void*, short);
void* fn_101_587C(void*, short);
void* fn_101_5908(void*, short);
void* fn_101_6CAC(void*, short);
}

extern "C" void* fn_101_20458(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3BA8(members + 0x4B0, memberDeleting);
        fn_101_57F0(members + 0x384, memberDeleting);
        fn_101_587C(members + 0x258, memberDeleting);
        fn_101_5908(members + 0x12C, memberDeleting);
        fn_101_6CAC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
