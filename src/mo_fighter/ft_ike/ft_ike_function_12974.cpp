#pragma force_active on
extern "C" void* fn_119_22A8(void* object, short param);
extern "C" void* fn_119_21CC(void* object, short param);

extern "C" void* fn_119_12974(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_22A8(storage + 0x50, -1);
        fn_119_21CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
