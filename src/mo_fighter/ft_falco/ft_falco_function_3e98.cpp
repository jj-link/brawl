#pragma force_active on
extern "C" void* fn_108_3F20(void*, short);
extern "C" void* fn_108_3F60(void*, short);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_3E98(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_108_3F20(storage + 0x24, 0);
        }
        fn_108_3F60(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
