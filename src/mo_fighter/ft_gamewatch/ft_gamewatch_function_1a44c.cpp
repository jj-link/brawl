#pragma force_active on
extern "C" {
void* fn_107_3984(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_107_1A4D4(void*, short);
void* fn_27_1D81C8(void*, short);
}

void operator delete(void*);

extern "C" void* fn_107_1A44C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_3984(members + 0x2060, memberDeleting);
        fn_27_1DBB60(members + 0x2028, memberDeleting);
        fn_107_1A4D4(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
