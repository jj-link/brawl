#pragma force_active on
extern "C" void* fn_92_22E0(void* object, short flag);
extern "C" void* fn_92_2204(void* object, short shouldDelete);

extern "C" void* fn_92_3A38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_22E0(storage + 0x50, -1);
        fn_92_2204(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
