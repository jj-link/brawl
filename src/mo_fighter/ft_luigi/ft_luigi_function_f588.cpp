extern "C" void* fn_99_F588(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}
