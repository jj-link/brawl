#pragma force_active on
extern "C" void* fn_113_F68(void* object, short flag);
extern "C" void* fn_113_D68(void* object, short deleting);

extern "C" void* fn_113_EFC(void* object, short deleting) {
    if (object != 0) {
        short neg = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_F68(storage + 0x50, neg);
        fn_113_D68(object, neg);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
