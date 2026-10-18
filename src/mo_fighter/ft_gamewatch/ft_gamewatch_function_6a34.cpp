#pragma force_active on
extern "C" void* fn_107_3E64(void* object, short deleting);
extern "C" void* fn_107_3EE8(void* object, short deleting);
extern "C" void* fn_107_6AD0(void* object, short deleting);
extern "C" void* fn_107_6B2C(void* object, short deleting);
extern "C" void* fn_107_7544(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_107_6A34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_3E64(storage + 0xE34, -1);
        fn_107_3EE8(storage + 0xE20, -1);
        fn_107_6AD0(storage + 0x930, -1);
        fn_107_6B2C(storage + 0xBC, -1);
        fn_107_7544(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
