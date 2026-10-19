#pragma force_active on
extern "C" void fn_109_1EB4(void*, short);
extern "C" void fn_109_1F10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_3ED8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_1EB4(storage + 0x14, 0);
        fn_109_1F10(storage + 0x8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
