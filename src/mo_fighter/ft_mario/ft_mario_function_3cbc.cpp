#pragma force_active on
extern "C" {
void* fn_27_6A3D8(void*, short);
void* fn_27_199E3C(void*, short);

void* fn_91_3CBC(void* object, short deleting) {
    if (object != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x144, static_cast<short>(-1));
        fn_27_199E3C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
