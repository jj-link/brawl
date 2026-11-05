#pragma force_active on
extern "C" {
void* fn_99_2054(void*, short);
void* fn_99_2218(void*, short);
void* fn_99_22E0(void*, short);
void* fn_99_236C(void*, short);
void* fn_99_23F8(void*, short);
void* fn_99_2484(void*, short);
void* fn_99_2510(void*, short);
void* fn_99_259C(void*, short);
void* fn_99_2628(void*, short);
void* fn_99_26B4(void*, short);
void* fn_99_2740(void*, short);
}

extern "C" void* fn_99_1F7C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroying = -1;
        fn_99_2054(storage + 0x14A0, destroying);
        fn_99_2218(storage + 0x137C, destroying);
        fn_99_22E0(storage + 0x1250, destroying);
        fn_99_236C(storage + 0x1124, destroying);
        fn_99_23F8(storage + 0xFF8, destroying);
        fn_99_2484(storage + 0xECC, destroying);
        fn_99_2510(storage + 0xDA0, destroying);
        fn_99_259C(storage + 0xC74, destroying);
        fn_99_2628(storage + 0xB48, destroying);
        fn_99_26B4(storage + 0xA1C, destroying);
        fn_99_2740(object, destroying);
        if (deleting > 0) operator delete(object);
    }
    return object;
}