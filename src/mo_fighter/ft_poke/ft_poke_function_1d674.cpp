#pragma force_active on
extern "C" void* fn_116_1D6E0(void* object, short deleting);
extern "C" void* fn_116_1DBB8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_1D674(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_1D6E0(storage + 0x1710, -1);
        fn_116_1DBB8(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
