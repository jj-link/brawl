#pragma force_active on
extern "C" void* fn_104_421C(void*, short);
extern "C" void* fn_104_425C(void*, short);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_4194(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_104_421C(storage + 0x24, 0);
        }
        fn_104_425C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
