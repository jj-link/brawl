#pragma force_active on
extern "C" void* fn_95_5938(void* object, short deleting);
extern "C" void* fn_95_5BDC(void* object, short deleting);

extern "C" void* fn_95_5B70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_5938(storage + 0x3E78, -1);
        fn_95_5BDC(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
