#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A2B08(void*, short);

extern "C" void* fn_102_3C4C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2B08(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
