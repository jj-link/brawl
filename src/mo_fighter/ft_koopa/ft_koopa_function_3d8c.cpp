#pragma force_active on
extern "C" void* fn_102_1E8C(void*, short);
extern "C" void* fn_102_1EE8(void*, short);

extern "C" void* fn_102_3D8C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_1E8C(storage + 0x14, 0);
        fn_102_1EE8(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
