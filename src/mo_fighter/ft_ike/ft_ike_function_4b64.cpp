#pragma force_active on
extern "C" void fn_27_4E038(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19D5E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_4B64(void* object, short deleting) {
    short s = -1;
    if (object != 0) {
        fn_27_4E038(static_cast<unsigned char*>(object) + 0x150, s);
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0xCC, s);
        fn_27_19D5E8(object, s);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
