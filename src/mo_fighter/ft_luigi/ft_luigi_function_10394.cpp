extern "C" void* fn_99_10394(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}
