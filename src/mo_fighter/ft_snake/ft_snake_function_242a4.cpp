#pragma force_active on
extern "C" void* fn_122_40A0(void*, short);
extern "C" void* fn_122_4124(void*, short);
extern "C" void* fn_122_58E0(void*, short);
extern "C" void* fn_122_4184(void*, short);
extern "C" void* fn_122_24340(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern void operator delete(void*);

extern "C" void* fn_122_242A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_40A0(storage + 0x12c, -1);
        fn_122_4124(storage + 0x118, -1);
        fn_122_58E0(storage + 0x100, -1);
        fn_122_4184(storage + 0x5c, -1);
        fn_122_24340(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
