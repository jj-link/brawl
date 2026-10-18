#pragma force_active on
extern "C" void* fn_109_B0E8(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_109_96B4(void* object, short deleting) {
    if (object != 0) {
        fn_109_B0E8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
