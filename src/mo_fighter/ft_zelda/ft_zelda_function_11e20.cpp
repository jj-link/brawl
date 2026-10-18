#pragma force_active on
extern "C" void* fn_104_3F88(void*, short);
extern "C" void* fn_104_400C(void*, short);
extern "C" void* fn_104_11EBC(void*, short);
extern "C" void* fn_104_406C(void*, short);
extern "C" void* fn_104_11F18(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_104_11E20(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_3F88(storage + 0x134, -1);
        fn_104_400C(storage + 0x120, -1);
        fn_104_11EBC(storage + 0x10c, -1);
        fn_104_406C(storage + 0x68, -1);
        fn_104_11F18(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
