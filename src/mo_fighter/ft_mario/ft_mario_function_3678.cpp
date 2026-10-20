#pragma force_active on
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_47CCC(void*, short);
void* fn_27_19958C(void*, short);
void* fn_27_19FCBC(void*, short);
void* fn_27_19D830(void*, short);

void* fn_91_3678(void* object, short deleting) {
    if (object != 0) {
        fn_27_48BE8(static_cast<unsigned char*>(object) + 0x844, static_cast<short>(-1));
        fn_27_47CCC(static_cast<unsigned char*>(object) + 0x834, static_cast<short>(-1));
        fn_27_19958C(static_cast<unsigned char*>(object) + 0x6c0, static_cast<short>(-1));
        fn_27_19FCBC(static_cast<unsigned char*>(object) + 0x48c, static_cast<short>(-1));
        fn_27_19D830(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
