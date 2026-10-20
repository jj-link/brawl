#pragma force_active on
extern "C" {
void fn_114_3AA0(void*, short);
void fn_27_1DBB60(void*, short);
void fn_114_1DD54(void*, short);
void fn_27_1D81C8(void*, short);
}

void operator delete(void*);

extern "C" void* fn_114_1DCCC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_3AA0(members + 0x1B94, memberDeleting);
        fn_27_1DBB60(members + 0x1B5C, memberDeleting);
        fn_114_1DD54(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
