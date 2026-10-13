void operator delete(void*);

extern "C" void* fn_117_43A8(void*, short);

extern "C" void* fn_117_1538C(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_117_43A8(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
