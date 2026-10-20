#pragma force_active on
extern "C" {
void* fn_107_3A20(void*, short);
void* fn_107_1E8AC(void*, short);
void* fn_107_1E938(void*, short);
void* fn_107_1E9C4(void*, short);
void* fn_107_1EA50(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_107_1E81C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_3A20(members + 0x4B0, memberDeleting);
        fn_107_1E8AC(members + 0x384, memberDeleting);
        fn_107_1E938(members + 0x258, memberDeleting);
        fn_107_1E9C4(members + 0x12C, memberDeleting);
        fn_107_1EA50(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
