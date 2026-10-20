#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_D568(void* object, short deleting);
extern "C" void fn_125_D434(void* object, short deleting);

extern "C" void* fn_125_D5C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_D568(storage + 0x204, -1);
        if (object != 0) {
            fn_125_D434(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
