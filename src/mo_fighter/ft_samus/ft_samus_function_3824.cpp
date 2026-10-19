#pragma force_active on
extern "C" void* fn_94_3890(void*, short);
extern "C" void* fn_94_38F0(void*, short);

extern "C" void* fn_94_3824(void* object, short deleting) {
    if (object != 0) {
        fn_94_3890(static_cast<unsigned char*>(object) + 0x3260, -1);
        fn_94_38F0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
