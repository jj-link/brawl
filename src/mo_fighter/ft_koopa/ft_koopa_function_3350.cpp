#pragma force_active on
extern "C" {
void* fn_102_33C0(void*, short);
void* fn_102_402C(void*, short);
}

extern "C" void* fn_102_3350(void* object, short deleting) {
    if (object != 0) {
        fn_102_33C0(static_cast<unsigned char*>(object) + 0x9DB0, static_cast<short>(-1));
        fn_102_402C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
