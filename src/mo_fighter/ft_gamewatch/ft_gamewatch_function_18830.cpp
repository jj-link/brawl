#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_107_46D0(void*, short);
extern "C" void* fn_107_472C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_18830(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0xd8, -1);
        fn_27_21038(static_cast<unsigned char*>(object) + 0xc4, -1);
        fn_107_46D0(static_cast<unsigned char*>(object) + 0x88, -1);
        fn_107_472C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
