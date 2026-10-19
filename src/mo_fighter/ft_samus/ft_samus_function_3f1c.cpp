#pragma force_active on
extern "C" void* fn_94_3F88(void* object, short deleting);
extern "C" void* fn_94_3FE8(void* object, short deleting);

extern "C" void* fn_94_3F1C(void* object, short deleting) {
    if (object != 0) {
        fn_94_3F88(static_cast<unsigned char*>(object) + 0x1934, -1);
        fn_94_3FE8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
