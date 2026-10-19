#pragma force_active on
extern "C" void* fn_94_3BDC(void* object, short deleting);
extern "C" void* fn_94_3CA8(void* object, short deleting);

extern "C" void* fn_94_3C3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_3BDC(storage + 0x2FA8, -1);
        fn_94_3CA8(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
