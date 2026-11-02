#pragma force_active on

void operator delete(void*);

extern "C" void* fn_108_2128(void*, short);
extern "C" void* fn_108_22EC(void*, short);
extern "C" void* fn_108_23B4(void*, short);
extern "C" void* fn_108_2440(void*, short);
extern "C" void* fn_108_24CC(void*, short);
extern "C" void* fn_108_2558(void*, short);
extern "C" void* fn_108_25E4(void*, short);
extern "C" void* fn_108_2670(void*, short);
extern "C" void* fn_108_26FC(void*, short);
extern "C" void* fn_108_2788(void*, short);
extern "C" void* fn_108_2814(void*, short);

extern "C" void* fn_108_2050(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_2128(storage + 0x14A0, -1);
        fn_108_22EC(storage + 0x137C, -1);
        fn_108_23B4(storage + 0x1250, -1);
        fn_108_2440(storage + 0x1124, -1);
        fn_108_24CC(storage + 0xFF8, -1);
        fn_108_2558(storage + 0xECC, -1);
        fn_108_25E4(storage + 0xDA0, -1);
        fn_108_2670(storage + 0xC74, -1);
        fn_108_26FC(storage + 0xB48, -1);
        fn_108_2788(storage + 0xA1C, -1);
        fn_108_2814(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
