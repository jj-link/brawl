#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_119_5298(void*, short);
extern "C" void* fn_119_11904(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_1197C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xD8, static_cast<short>(-1));
        fn_27_21038(storage + 0xC4, static_cast<short>(-1));
        fn_119_5298(storage + 0x88, static_cast<short>(-1));
        fn_119_11904(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
