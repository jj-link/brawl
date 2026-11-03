#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_2180(void*, short);
extern "C" void* fn_125_2344(void*, short);
extern "C" void* fn_125_240C(void*, short);
extern "C" void* fn_125_2498(void*, short);
extern "C" void* fn_125_2524(void*, short);
extern "C" void* fn_125_25B0(void*, short);
extern "C" void* fn_125_263C(void*, short);
extern "C" void* fn_125_26C8(void*, short);
extern "C" void* fn_125_2754(void*, short);
extern "C" void* fn_125_27E0(void*, short);
extern "C" void* fn_125_286C(void*, short);

extern "C" void* fn_125_20A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_2180(storage + 0x14B8, -1);
        fn_125_2344(storage + 0x1394, -1);
        fn_125_240C(storage + 0x1268, -1);
        fn_125_2498(storage + 0x113C, -1);
        fn_125_2524(storage + 0x1010, -1);
        fn_125_25B0(storage + 0xEE4, -1);
        fn_125_263C(storage + 0xDB8, -1);
        fn_125_26C8(storage + 0xC8C, -1);
        fn_125_2754(storage + 0xB60, -1);
        fn_125_27E0(storage + 0xA34, -1);
        fn_125_286C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
