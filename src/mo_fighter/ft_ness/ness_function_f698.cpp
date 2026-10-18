#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_F638(void*, short);

extern "C" void* fn_101_F698(void* object, short deleting) {
    if (object != 0) {
        fn_101_F638(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
