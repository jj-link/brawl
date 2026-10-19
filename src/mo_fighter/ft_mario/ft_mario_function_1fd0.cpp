#pragma force_active on
extern "C" {
void* fn_27_25740(void*, short);
void* fn_27_CC0F0(void*, short);

void* fn_91_1FD0(void* object, short deleting) {
    if (object != 0) {
        fn_27_25740(static_cast<unsigned char*>(object) + 0x50, static_cast<short>(-1));
        fn_27_CC0F0(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
