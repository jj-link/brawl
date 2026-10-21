#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_104_725C(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_104_72C8(void*, short);
extern "C" void* fn_104_7324(void*, short);
extern "C" void* fn_104_7380(void*, short);
extern "C" void* fn_104_73DC(void*, short);
extern "C" void* fn_104_7438(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_19B18(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, flag);
        fn_104_725C(storage + 0x1E8, flag);
        fn_27_21038(storage + 0x1D8, flag);
        fn_104_72C8(storage + 0x1B8, flag);
        fn_104_7324(storage + 0x198, flag);
        fn_104_7380(storage + 0x160, flag);
        fn_104_73DC(storage + 0xC4, flag);
        fn_104_7438(object, flag);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
