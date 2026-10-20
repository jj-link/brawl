#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_D0A8(void* object, short deleting);
extern "C" void fn_125_CF74(void* object, short deleting);

extern "C" void* fn_125_D108(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_D0A8(storage + 0x134, -1);
        if (object != 0) {
            fn_125_CF74(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
