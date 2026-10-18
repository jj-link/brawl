#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_F7CC(void*, short);

extern "C" void* fn_101_F82C(void* object, short deleting) {
    if (object != 0) {
        fn_101_F7CC(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
