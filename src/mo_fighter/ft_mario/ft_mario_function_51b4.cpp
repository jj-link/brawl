#pragma force_active on
extern "C" {
void* fn_91_2C9C(void*, short);
void* fn_91_5154(void*, short);
void* fn_27_19E99C(void*, short);
}

extern "C" void* fn_91_51B4(void* object, short deleting) {
    if (object != 0) {
        fn_91_2C9C(static_cast<unsigned char*>(object) + 0x85c, static_cast<short>(-1));
        fn_91_5154(static_cast<unsigned char*>(object) + 0x19c, static_cast<short>(-1));
        fn_27_19E99C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
