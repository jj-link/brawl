extern "C" void* fn_27_1A1E70(void*, short);

extern "C" void* fn_99_F868(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyBase = -1;
            fn_27_1A1E70(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
