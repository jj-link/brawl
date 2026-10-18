#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_135E8(void*, short);

extern "C" void* fn_120_3444(void* object, short deleting) {
    if (object != 0) {
        fn_120_135E8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
