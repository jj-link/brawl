#pragma force_active on
void operator delete(void*);
extern "C" void fn_102_A668(void*, short);

extern "C" void* fn_102_A6C8(void* object, short deleting) {
    if (object != 0) {
        fn_102_A668(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
