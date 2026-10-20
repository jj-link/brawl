#pragma force_active on
extern "C" void* fn_92_4114(void* ptr, short count);
extern "C" void* fn_92_4154(void* object, short deleting);
extern "C" void* fn_27_1A262C(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_408C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_92_4114(storage + 0x24, 0);
        }
        fn_92_4154(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
