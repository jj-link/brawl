#pragma force_active on
extern "C" void* fn_27_13C90(void* object, short deleting);
extern "C" void* fn_104_725C(void* object, short deleting);
extern "C" void* fn_27_21038(void* object, short deleting);
extern "C" void* fn_104_72C8(void* object, short deleting);
extern "C" void* fn_104_7324(void* object, short deleting);
extern "C" void* fn_104_7380(void* object, short deleting);
extern "C" void* fn_104_73DC(void* object, short deleting);
extern "C" void* fn_104_7438(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_71A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_104_725C(storage + 0x1e8, -1);
        fn_27_21038(storage + 0x1d8, -1);
        fn_104_72C8(storage + 0x1b8, -1);
        fn_104_7324(storage + 0x198, -1);
        fn_104_7380(storage + 0x160, -1);
        fn_104_73DC(storage + 0xc4, -1);
        fn_104_7438(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
