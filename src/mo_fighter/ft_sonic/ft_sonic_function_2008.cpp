#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_20E0(void*, short);
extern "C" void* fn_123_22A4(void*, short);
extern "C" void* fn_123_236C(void*, short);
extern "C" void* fn_123_23F8(void*, short);
extern "C" void* fn_123_2484(void*, short);
extern "C" void* fn_123_2510(void*, short);
extern "C" void* fn_123_259C(void*, short);
extern "C" void* fn_123_2628(void*, short);
extern "C" void* fn_123_26B4(void*, short);
extern "C" void* fn_123_2740(void*, short);
extern "C" void* fn_123_27CC(void*, short);

extern "C" void* fn_123_2008(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_20E0(storage + 0x14F0, -1);
        fn_123_22A4(storage + 0x13CC, -1);
        fn_123_236C(storage + 0x12A0, -1);
        fn_123_23F8(storage + 0x1174, -1);
        fn_123_2484(storage + 0x1048, -1);
        fn_123_2510(storage + 0xF1C, -1);
        fn_123_259C(storage + 0xDF0, -1);
        fn_123_2628(storage + 0xCC4, -1);
        fn_123_26B4(storage + 0xB98, -1);
        fn_123_2740(storage + 0xA6C, -1);
        fn_123_27CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
