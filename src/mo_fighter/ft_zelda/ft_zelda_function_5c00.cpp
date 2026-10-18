#pragma force_active on
extern "C" void* fn_104_3F88(void*, short);
extern "C" void* fn_104_400C(void*, short);
extern "C" void* fn_104_5C9C(void*, short);
extern "C" void* fn_104_5CF8(void*, short);
extern "C" void* fn_104_6710(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

void operator delete(void*);

extern "C" void* fn_104_5C00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_3F88(storage + 0xE00, -1);
        fn_104_400C(storage + 0xDEC, -1);
        fn_104_5C9C(storage + 0x970, -1);
        fn_104_5CF8(storage + 0xFC, -1);
        fn_104_6710(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
