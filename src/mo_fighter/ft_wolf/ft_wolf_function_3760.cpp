#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_22E8(void*, short);
extern "C" void* fn_125_220C(void*, short);

extern "C" void* fn_125_3760(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_22E8(storage + 0x50, -1);
        fn_125_220C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
