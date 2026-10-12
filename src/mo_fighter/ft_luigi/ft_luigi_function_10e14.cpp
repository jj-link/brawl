void operator delete(void*);

extern "C" void* fn_99_10E14(void* object, short deleting) {
    if (object && deleting > 0) {
        operator delete(object);
    }
    return object;
}
