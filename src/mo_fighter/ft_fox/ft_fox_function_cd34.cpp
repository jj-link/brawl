#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_CCD4(void*, short);
extern "C" void* fn_97_CBB4(void*, short);

extern "C" void* fn_97_CD34(void* object, short deleting) {
    if (object != 0) {
        fn_97_CCD4(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_97_CBB4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
