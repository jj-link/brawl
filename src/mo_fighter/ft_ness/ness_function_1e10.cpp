#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_1D50(void*, short);

extern "C" void* fn_101_1E10(void* object, short deleting) {
    if (object != 0) {
        fn_101_1D50(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
