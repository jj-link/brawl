#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_527C(void*, short);
extern "C" void* fn_125_55F4(void*, short);

extern "C" void* fn_125_5210(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_527C(storage + 0x1DF4, -1);
        fn_125_55F4(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
