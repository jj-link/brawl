extern "C" void* fn_27_5C674(void*, short);

extern "C" void* fn_99_F344(void* object, short deleting) {
    if (object) {
        int destroyBase = -1;
        fn_27_5C674(object, destroyBase);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
