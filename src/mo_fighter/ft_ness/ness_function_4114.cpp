#pragma force_active on
extern "C" void* fn_27_1A2B08(void*, short);
void operator delete(void*);

extern "C" void* fn_101_4114(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2B08(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
