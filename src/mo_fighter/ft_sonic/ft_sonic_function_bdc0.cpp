#pragma force_active on
extern "C" void* fn_123_BD60(void* object, short deleting);
extern "C" void* fn_123_BC2C(void* object, short deleting);

extern "C" void* fn_123_BDC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_BD60(storage + 0x134, -1);
        if (object != 0) {
            fn_123_BC2C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
