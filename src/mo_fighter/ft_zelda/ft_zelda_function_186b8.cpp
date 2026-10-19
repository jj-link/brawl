#pragma force_active on
extern "C" void* fn_104_17EF8(void* object, short deleting);
extern "C" void* fn_104_18724(void* object, short deleting);

extern "C" void* fn_104_186B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_17EF8(storage + 0x5390, -1);
        fn_104_18724(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
