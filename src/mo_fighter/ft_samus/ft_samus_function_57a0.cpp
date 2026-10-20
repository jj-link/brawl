#pragma force_active on
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_94_5818(void* object, short deleting);

extern "C" void* fn_94_57A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x154, -1);
        if (object != 0) {
            fn_94_5818(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
