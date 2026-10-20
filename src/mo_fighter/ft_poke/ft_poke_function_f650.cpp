#pragma force_active on
extern "C" {
void* fn_116_37E8(void* ptr, short flag);
void* fn_27_1DBB60(void*, short);
void* fn_116_F6D8(void* object, short deleting);
void* fn_27_1D81C8(void* self, short flag);
}

void operator delete(void*);

extern "C" void* fn_116_F650(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_37E8(members + 0x18A4, memberDeleting);
        fn_27_1DBB60(members + 0x186C, memberDeleting);
        fn_116_F6D8(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
