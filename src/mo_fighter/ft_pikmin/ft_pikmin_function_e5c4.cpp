#pragma force_active on
extern "C" void* fn_113_E564(void* object, short deleting);
extern "C" void* fn_113_E434(void* object, short deleting);

extern "C" void* fn_113_E5C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_E564(storage + 0x94, -1);
        if (object != 0) {
            fn_113_E434(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
