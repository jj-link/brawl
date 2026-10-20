#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_91_21B8(void*, short);
void* fn_91_68F8(void*, short);
}

void* fn_91_68F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(-1));
        if (static_cast<unsigned char*>(object) + 0x10 != 0) fn_91_21B8(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(0));
        if (object != 0) fn_91_21B8(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
