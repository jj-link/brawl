#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_99_4DA4(void*, short);

extern "C" void* fn_99_4D2C(void* object, short deleting) {
    if (object) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xf0, -1);
        if (object) {
            fn_99_4DA4(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
