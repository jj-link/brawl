#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_48BC(void*, short);
extern "C" void* fn_125_5068(void*, short);

extern "C" void* fn_125_4FFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_48BC(storage + 0x6488, -1);
        fn_125_5068(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
