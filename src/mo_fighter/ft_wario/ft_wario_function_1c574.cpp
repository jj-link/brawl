#pragma force_active on

void operator delete(void*);

extern "C" void* fn_27_5AE44(void*, short);

extern "C" void* fn_110_1C574(void* object, short deleting) {
    if (object != 0) {
        fn_27_5AE44(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
