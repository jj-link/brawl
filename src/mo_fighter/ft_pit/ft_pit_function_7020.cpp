#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_112_3BE4(void*, short);
extern "C" void* fn_112_70D4(void*, short);
extern "C" void* fn_112_7140(void*, short);
extern "C" void* fn_112_719C(void*, short);
extern "C" void* fn_112_71F8(void*, short);
extern "C" void* fn_112_7254(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_7020(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_112_70D4(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_112_7140(storage + 0x1B8, -1);
        fn_112_719C(storage + 0x198, -1);
        fn_112_3BE4(storage + 0x160, -1);
        fn_112_71F8(storage + 0xC4, -1);
        fn_112_7254(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
