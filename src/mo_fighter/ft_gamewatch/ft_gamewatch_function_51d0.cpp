#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_107_46D0(void*, short);
void* fn_107_472C(void*, short);
}

extern "C" void* fn_107_51D0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_13C90(members + 0xD8, -1);
        fn_27_21038(members + 0xC4, -1);
        fn_107_46D0(members + 0x88, -1);
        fn_107_472C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
