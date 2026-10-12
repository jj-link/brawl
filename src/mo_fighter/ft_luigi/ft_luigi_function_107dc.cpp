extern "C" void* fn_99_107DC(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}
