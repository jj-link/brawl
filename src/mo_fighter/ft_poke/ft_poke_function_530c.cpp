#pragma force_active on
extern "C" void* fn_116_4EB8(void*, short);
extern "C" void* fn_116_5378(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_530C(void* object, short deleting) {
    if (object != 0) {
        fn_116_4EB8(static_cast<unsigned char*>(object) + 0x16EC, -1);
        fn_116_5378(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
