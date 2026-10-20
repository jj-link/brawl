#pragma force_active on
extern "C" void* fn_119_3A14(void* object, short deleting);
extern "C" void* fn_119_3AB4(void* object, short deleting);
extern "C" void* fn_27_19E99C(void* object, short deleting);

extern "C" void* fn_119_399C(void* object, short deleting) {
    if (object != 0) {
        fn_119_3A14(static_cast<unsigned char*>(object) + 0x85c, -1);
        fn_119_3AB4(static_cast<unsigned char*>(object) + 0x19c, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
