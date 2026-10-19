#pragma force_active on
extern "C" void* fn_102_11A3C(void* object, short deleting);
extern "C" void* fn_102_12278(void* object, short deleting);

extern "C" void* fn_102_1220C(void* object, short deleting) {
    if (object != 0) {
        fn_102_11A3C(static_cast<unsigned char*>(object) + 0x1f90, -1);
        fn_102_12278(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
