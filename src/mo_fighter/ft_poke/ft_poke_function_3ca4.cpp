#pragma force_active on
extern "C" void* fn_27_75E0C(void*, short);
extern "C" void* fn_27_64930(void*, short);
extern "C" void fn_116_1EC4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_3CA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_75E0C(storage + 0x4C, -1);
        if (storage + 0x20 != 0) {
            fn_27_64930(storage + 0x20, 0);
        }
        fn_116_1EC4(storage + 0x14, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
