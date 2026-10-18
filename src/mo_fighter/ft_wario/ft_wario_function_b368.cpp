#pragma force_active on
extern "C" void* fn_110_B308(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_110_B368(void* object, short deleting) {
    if (object != 0) {
        fn_110_B308(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
