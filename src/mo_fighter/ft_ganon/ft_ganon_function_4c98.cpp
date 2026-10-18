#pragma force_active on
extern "C" void* fn_109_3C8C(void* object, short deleting);
extern "C" void* fn_109_3D10(void* object, short deleting);
extern "C" void* fn_109_4D34(void* object, short deleting);
extern "C" void* fn_109_4D90(void* object, short deleting);
extern "C" void* fn_109_57A8(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_109_4C98(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_3C8C(storage + 0xdd8, -1);
        fn_109_3D10(storage + 0xdc4, -1);
        fn_109_4D34(storage + 0x930, -1);
        fn_109_4D90(storage + 0xbc, -1);
        fn_109_57A8(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
