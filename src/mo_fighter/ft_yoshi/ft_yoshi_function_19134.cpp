#pragma force_active on
extern "C" {
void* fn_95_3808(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_95_191BC(void*, short);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_19134(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_3808(members + 0x209C, memberDeleting);
        fn_27_1DBB60(members + 0x2064, memberDeleting);
        fn_95_191BC(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
