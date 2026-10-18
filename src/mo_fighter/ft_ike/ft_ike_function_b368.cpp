#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_B30C(void*, short);

extern "C" void* fn_119_B368(void* object, short deleting) {
    if (object != 0) {
        fn_119_B30C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
