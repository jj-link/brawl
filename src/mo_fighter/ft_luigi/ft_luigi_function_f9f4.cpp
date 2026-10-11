extern "C" void* fn_27_5AE44(void*, short);

extern "C" void* fn_99_F9F4(void* object, short deleting) {
    if (object) {
        int destroyBase = -1;
        fn_27_5AE44(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
