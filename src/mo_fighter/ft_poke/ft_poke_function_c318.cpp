#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_C2B8(void*, short);

extern "C" void* fn_116_C318(void* object, short deleting) {
    if (object != 0) {
        fn_116_C2B8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
