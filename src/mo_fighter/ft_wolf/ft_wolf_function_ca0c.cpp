#pragma force_active on
extern "C" void* fn_125_C9AC(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_125_CA0C(void* object, short deleting) {
    if (object != 0) {
        fn_125_C9AC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
