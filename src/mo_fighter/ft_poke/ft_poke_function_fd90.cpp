#pragma force_active on
extern "C" {
void* fn_116_3CA4(void*, short);
void* fn_116_3D28(void*, short);
void* fn_116_FE2C(void*, short);
void* fn_116_4ADC(void*, short);
void* fn_116_FE88(void*, short);
void* fn_27_C74E8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_FD90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_3CA4(storage + 0xCC, -1);
        fn_116_3D28(storage + 0xB8, -1);
        fn_116_FE2C(storage + 0x98, -1);
        fn_116_4ADC(storage + 0x44, -1);
        fn_116_FE88(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
