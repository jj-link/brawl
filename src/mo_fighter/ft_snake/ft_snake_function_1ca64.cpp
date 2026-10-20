#pragma force_active on
extern "C" {
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_1CAEC(void*, short);
void* fn_27_1D81C8(void*, short);
}

void operator delete(void*);

extern "C" void* fn_122_1CA64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_3958(members + 0x21cc, memberDeleting);
        fn_27_1DBB60(members + 0x2194, memberDeleting);
        fn_122_1CAEC(members + 0xcc, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
