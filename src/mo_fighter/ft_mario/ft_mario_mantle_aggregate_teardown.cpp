extern "C" {
void* fn_91_6308(void*, short);
void* fn_91_6364(void*, short);
void* fn_91_63C0(void*, short);
void* fn_91_64A8(void*, short);
void* fn_91_2258(void*, short);
void* fn_91_6714(void*, short);
void* fn_91_6770(void*, short);
void* fn_91_67DC(void*, short);
void* fn_91_683C(void*, short);
void* fn_91_689C(void*, short);
void* fn_91_68F8(void*, short);
void* fn_91_FC34(void*, short);
void* fn_91_FC94(void*, short);
void* fn_91_6A0C(void*, short);
void* fn_91_6A78(void*, short);
void* fn_91_6AF0(void*, short);
void* fn_91_1F00(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_91_6B30(void*, short);
// Member destructor calls use the original non-deleting flag and reverse
// construction order; only the aggregate itself may release its storage.
void* fn_91_FAA0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        const short destroyMember = -1;
        fn_91_6308(static_cast<unsigned char*>(object) + 0x1240, destroyMember);
        fn_91_6364(members + 0x1228, destroyMember);
        fn_91_63C0(members + 0x108c, destroyMember);
        fn_91_64A8(members + 0x102c, destroyMember);
        fn_91_2258(members + 0x0ff0, destroyMember);
        fn_91_6714(members + 0x0fd8, destroyMember);
        fn_91_6770(members + 0x0e74, destroyMember);
        fn_91_67DC(members + 0x0e0c, destroyMember);
        fn_91_683C(members + 0x0e00, destroyMember);
        fn_91_689C(members + 0x0dd8, destroyMember);
        fn_91_68F8(members + 0x0d68, destroyMember);
        fn_91_FC34(members + 0x0d1c, destroyMember);
        fn_91_FC94(members + 0x0b10, destroyMember);
        fn_91_6A0C(members + 0x0930, destroyMember);
        fn_91_6A78(members + 0x0900, destroyMember);
        fn_91_6AF0(members + 0x08f0, destroyMember);
        fn_91_1F00(members + 0x08d8, destroyMember);
        __dt__16soModuleAccesserFv(members + 0x07f8, destroyMember);
        fn_91_6B30(members, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
