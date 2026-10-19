#pragma force_active on
extern "C" void* fn_102_11A3C(void* object, short deleting);
extern "C" void* fn_102_12134(void* object, short deleting);

extern "C" void* fn_102_120C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_11A3C(storage + 0x7E28, -1);
        fn_102_12134(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
