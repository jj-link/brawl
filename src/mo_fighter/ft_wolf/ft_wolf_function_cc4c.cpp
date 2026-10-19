#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_CBEC(void*, short);
extern "C" void* fn_125_CACC(void*, short);

extern "C" void* fn_125_CC4C(void* object, short deleting) {
    if (object != 0) {
        fn_125_CBEC(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_125_CACC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
