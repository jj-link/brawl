#pragma force_active on
extern "C" void* fn_104_2374(void* object, short deleting);
extern "C" void* fn_104_21D0(void* object, short deleting);

extern "C" void* fn_104_2308(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_2374(storage + 0x50, -1);
        fn_104_21D0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
