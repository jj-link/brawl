#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_120_127E0(void*, short);

extern "C" void* fn_120_12820(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0xC, -1);
        fn_120_127E0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
