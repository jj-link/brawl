#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_C31CC(void*, short);

extern "C" void* fn_116_394C(void* object, short deleting) {
    if (object != 0) {
        fn_27_C31CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
