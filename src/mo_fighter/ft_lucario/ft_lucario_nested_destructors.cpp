void operator delete(void*);
extern "C" void* fn_118_12F90(void*, short);
extern "C" void* fn_118_13250(void*, short);
extern "C" void* fn_118_3964(void*, short);
extern "C" void* fn_118_13020(void*, short);
extern "C" void* fn_118_130AC(void*, short);
extern "C" void* fn_118_13138(void*, short);
extern "C" void* fn_118_131C4(void*, short);

extern "C" void* fn_118_12F20(void* object, short deleting) {
    if (object != 0) {
        fn_118_12F90(static_cast<unsigned char*>(object) + 0x1714, -1);
        fn_118_13250(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

// Member storage is part of the enclosing object and must not be freed separately.
extern "C" void* fn_118_12F90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3964(storage + 0x4B0, -1);
        fn_118_13020(storage + 0x384, -1);
        fn_118_130AC(storage + 0x258, -1);
        fn_118_13138(storage + 0x12C, -1);
        fn_118_131C4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
