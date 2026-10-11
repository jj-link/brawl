void operator delete(void*);

extern "C" void* fn_101_3B0C(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
