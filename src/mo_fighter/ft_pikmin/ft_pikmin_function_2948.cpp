#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_E44(void*, short);
extern "C" void* fn_113_D68(void*, short);

extern "C" void* fn_113_2948(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_E44(storage + 0x50, -1);
        fn_113_D68(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
