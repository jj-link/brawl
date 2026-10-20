#pragma force_active on
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_107_46D0(void*, short);
void* fn_107_472C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_107_1EF48(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xd8, -1);
        fn_27_21038(storage + 0xc4, -1);
        fn_107_46D0(storage + 0x88, -1);
        fn_107_472C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
