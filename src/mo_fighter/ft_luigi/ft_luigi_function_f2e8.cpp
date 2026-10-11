extern "C" void* fn_27_63EBC(void*, short);

extern "C" void* fn_99_F2E8(void* object, short deleting) {
    if (object) {
        int destroyBase = -1;
        fn_27_63EBC(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
