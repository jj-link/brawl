#pragma force_active on
extern "C" {
void* fn_27_565F0(void*, short);
void* fn_91_3BBC(void*, short);

void* fn_91_3BFC(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        fn_91_3BBC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
