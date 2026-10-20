#pragma force_active on
extern "C" {
void* fn_108_4C24(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_108_10064(void*, short);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_108_FFDC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_108_4C24(members + 0x1F28, memberDeleting);
        fn_27_1DBB60(members + 0x1EF0, memberDeleting);
        fn_108_10064(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
