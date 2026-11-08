#pragma force_active on
extern "C" void* fn_104_3F88(void*, short);
extern "C" void* fn_104_400C(void*, short);
extern "C" void* fn_104_5164(void*, short);
extern "C" void* fn_104_406C(void*, short);
extern "C" void* fn_104_3DB0(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_5648(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_3F88(storage + 0x110, memberDeleting);
        fn_104_400C(storage + 0xFC, memberDeleting);
        fn_104_5164(storage + 0xEC, memberDeleting);
        fn_104_406C(storage + 0x48, memberDeleting);
        if (storage + 0x10 != 0) {
            fn_104_3DB0(storage + 0x24, memberDeleting);
        }
        fn_27_C74E8(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
