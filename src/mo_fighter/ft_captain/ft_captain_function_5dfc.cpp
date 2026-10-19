#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_100_5E68(void*, short);

extern "C" void* fn_100_5DFC(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_100_5E68(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
