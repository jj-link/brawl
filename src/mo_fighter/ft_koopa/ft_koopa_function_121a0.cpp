#pragma force_active on
extern "C" void* fn_102_11A3C(void*, short);
extern "C" void* fn_102_1220C(void*, short);

extern "C" void* fn_102_121A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_11A3C(storage + 0x3F18, -1);
        fn_102_1220C(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
