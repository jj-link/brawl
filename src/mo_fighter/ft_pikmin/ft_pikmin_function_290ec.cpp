#pragma force_active on
extern "C" void* fn_113_2C28(void*, short);
extern "C" void* fn_113_2CAC(void*, short);
extern "C" void* fn_113_29188(void*, short);
extern "C" void* fn_113_3F04(void*, short);
extern "C" void* fn_113_291E4(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

void operator delete(void*);

extern "C" void* fn_113_290EC(void* object, short deleting) {
    if (object != 0) {
        fn_113_2C28(static_cast<unsigned char*>(object) + 0x120, -1);
        fn_113_2CAC(static_cast<unsigned char*>(object) + 0x10C, -1);
        fn_113_29188(static_cast<unsigned char*>(object) + 0xEC, -1);
        fn_113_3F04(static_cast<unsigned char*>(object) + 0x48, -1);
        fn_113_291E4(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
