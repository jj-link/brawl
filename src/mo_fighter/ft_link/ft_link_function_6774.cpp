#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_93_21A0(void*, short);

extern "C" void* fn_93_6774(void* object, short deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x20, -1);
        if (static_cast<unsigned char*>(object) + 0x10 != 0) {
            fn_93_21A0(static_cast<unsigned char*>(object) + 0x10, 0);
        }
        if (object != 0) {
            fn_93_21A0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
