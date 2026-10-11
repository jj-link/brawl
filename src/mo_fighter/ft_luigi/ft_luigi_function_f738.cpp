extern "C" void* fn_27_1A301C(void*, short);

extern "C" void* fn_99_F738(void* object, short deleting) {
    if (object) {
        int destroyBase = -1;
        fn_27_1A301C(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
