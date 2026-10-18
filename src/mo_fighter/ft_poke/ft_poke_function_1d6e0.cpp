#pragma force_active on
void operator delete(void*);

extern "C" void fn_116_1D740(void*, short);

extern "C" void* fn_116_1D6E0(void* object, short deleting) {
    if (object != 0) {
        fn_116_1D740(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
