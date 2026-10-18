#pragma force_active on
extern "C" void* fn_94_4928(void*, short);
extern "C" void* fn_94_49AC(void*, short);
extern "C" void* fn_94_164D4(void*, short);
extern "C" void* fn_94_5128(void*, short);
extern "C" void* fn_94_5B40(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_16438(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_4928(storage + 0xdd4, -1);
        fn_94_49AC(storage + 0xdc0, -1);
        fn_94_164D4(storage + 0x930, -1);
        fn_94_5128(storage + 0xbc, -1);
        fn_94_5B40(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
