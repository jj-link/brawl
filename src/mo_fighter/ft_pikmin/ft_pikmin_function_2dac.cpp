#pragma force_active on
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_113_2E34(void*, short);
extern "C" void* fn_113_2E74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_2DAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_113_2E34(storage + 0x24, 0);
        }
        fn_113_2E74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
