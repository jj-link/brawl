#pragma force_active on
extern "C" void* fn_109_3E98(void* ptr, short count);
extern "C" void* fn_109_3ED8(void* object, short deleting);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_3E10(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_109_3E98(storage + 0x24, 0);
        }
        fn_109_3ED8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
