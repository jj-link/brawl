#pragma force_active on
extern "C" void* fn_27_1A15B8(void* object, short deleting);
extern "C" void fn_119_3E5C(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_119_3DE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x2fc, -1);
        if (object != 0) {
            fn_119_3E5C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
