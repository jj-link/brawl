#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_99_496C(void*, short);

extern "C" void* fn_99_48F4(void* object, short deleting) {
    if (object) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x2fc, -1);
        if (object) {
            fn_99_496C(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
