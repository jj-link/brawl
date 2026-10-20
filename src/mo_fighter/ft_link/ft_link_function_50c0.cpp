#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_93_5048(void*, short);

extern "C" void* fn_93_50C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A18A0(storage + 0x354, -1);
        if (object != 0) {
            fn_93_5048(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
