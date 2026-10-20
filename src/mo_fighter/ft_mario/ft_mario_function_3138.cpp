#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_91_21F8(void*, short);
void* fn_91_215C(void*, short);

void* fn_91_3138(void* object, short deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x30, static_cast<short>(-1));
        fn_91_21F8(static_cast<unsigned char*>(object) + 0x18, static_cast<short>(-1));
        fn_91_215C(static_cast<unsigned char*>(object) + 0x4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
