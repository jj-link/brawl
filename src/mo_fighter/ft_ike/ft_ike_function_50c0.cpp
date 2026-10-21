#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_119_5174(void*, short);
extern "C" void* fn_119_51E0(void*, short);
extern "C" void* fn_119_523C(void*, short);
extern "C" void* fn_119_5298(void*, short);
extern "C" void* fn_119_52F4(void*, short);
extern "C" void* fn_119_5350(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_50C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, static_cast<short>(-1));
        fn_119_5174(storage + 0x1E8, static_cast<short>(-1));
        fn_27_21038(storage + 0x1D8, static_cast<short>(-1));
        fn_119_51E0(storage + 0x1B8, static_cast<short>(-1));
        fn_119_523C(storage + 0x198, static_cast<short>(-1));
        fn_119_5298(storage + 0x160, static_cast<short>(-1));
        fn_119_52F4(storage + 0xC4, static_cast<short>(-1));
        fn_119_5350(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
