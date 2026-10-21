#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_122_A4E0(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_122_A54C(void*, short);
extern "C" void* fn_122_A5A8(void*, short);
extern "C" void* fn_122_8CFC(void*, short);
extern "C" void* fn_122_A604(void*, short);
extern "C" void* fn_122_A660(void*, short);

extern "C" void* fn_122_A42C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_122_A4E0(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_122_A54C(storage + 0x1B8, -1);
        fn_122_A5A8(storage + 0x198, -1);
        fn_122_8CFC(storage + 0x160, -1);
        fn_122_A604(storage + 0xC4, -1);
        fn_122_A660(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
