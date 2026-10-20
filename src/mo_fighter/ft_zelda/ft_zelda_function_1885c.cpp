#pragma force_active on
extern "C" void* fn_104_188D4(void*, short);
extern "C" void fn_104_18D38(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_1885C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_188D4(storage + 0x7EF4, -1);
        if (object != 0) {
            fn_104_18D38(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
