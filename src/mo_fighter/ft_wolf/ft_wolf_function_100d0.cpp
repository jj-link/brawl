#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_3760(void*, short);
extern "C" void* fn_125_37CC(void*, short);
extern "C" void* fn_125_3858(void*, short);
extern "C" void* fn_125_38E4(void*, short);
extern "C" void* fn_125_10160(void*, short);

extern "C" void* fn_125_100D0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_3760(storage + 0x4B0, -1);
        fn_125_37CC(storage + 0x384, -1);
        fn_125_3858(storage + 0x258, -1);
        fn_125_38E4(storage + 0x12C, -1);
        fn_125_10160(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
