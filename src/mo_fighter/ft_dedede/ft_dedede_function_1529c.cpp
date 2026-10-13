void operator delete(void*);

extern "C" void* fn_117_1529C(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
