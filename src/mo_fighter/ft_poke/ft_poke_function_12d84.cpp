#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_37E8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_116_12E0C(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_116_12D84(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_37E8(members + 0x1698, memberDeleting);
        fn_27_1DBB60(members + 0x1660, memberDeleting);
        fn_116_12E0C(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
