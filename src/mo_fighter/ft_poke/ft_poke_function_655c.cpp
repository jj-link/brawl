#pragma force_active on
extern "C" void fn_27_689B0(void*, short);
extern "C" void fn_27_1985B4(void*, short);

extern "C" void* fn_116_655C(void* object, short deleting) {
    if (object != 0) {
        fn_27_689B0(static_cast<unsigned char*>(object) + 0x7c, -1);
        if (object != 0) {
            fn_27_1985B4(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
