#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_AB2C(void*, short);

extern "C" void* fn_102_AB8C(void* object, short deleting) {
    if (object != 0) {
        fn_102_AB2C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
