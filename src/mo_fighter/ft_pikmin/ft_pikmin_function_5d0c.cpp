#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_113_3384(void*, short);
extern "C" void* fn_113_33F0(void*, short);
extern "C" void* fn_113_5DC0(void*, short);
extern "C" void* fn_113_5E1C(void*, short);
extern "C" void* fn_113_5E78(void*, short);
extern "C" void* fn_113_5ED4(void*, short);

extern "C" void* fn_113_5D0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_113_3384(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_113_5DC0(storage + 0x1B8, -1);
        fn_113_5E1C(storage + 0x198, -1);
        fn_113_33F0(storage + 0x160, -1);
        fn_113_5E78(storage + 0xC4, -1);
        fn_113_5ED4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
