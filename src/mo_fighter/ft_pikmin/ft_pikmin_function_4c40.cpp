#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_113_4CB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_4C40(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x470, -1);
        if (object != 0) {
            fn_113_4CB8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
