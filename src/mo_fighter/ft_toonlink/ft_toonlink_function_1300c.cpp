#pragma force_active on
extern "C" void* fn_121_4728(void*, short);
extern "C" void* fn_121_46C8(void*, short);
extern "C" void* fn_121_12FB0(void*, short);
extern "C" void* fn_121_12F38(void*, short);
extern "C" void* fn_121_12E1C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_121_1300C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_4728(storage + 0x11C, -1);
        fn_121_46C8(storage + 0x108, -1);
        fn_121_12FB0(storage + 0xEC, -1);
        fn_121_12F38(storage + 0x48, -1);
        fn_121_12E1C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
