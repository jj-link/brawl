#pragma force_active on
extern "C" void* fn_95_4C88(void*, short);
extern "C" void* fn_95_5224(void*, short);

extern "C" void* fn_95_51B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_4C88(storage + 0x4008, -1);
        fn_95_5224(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
