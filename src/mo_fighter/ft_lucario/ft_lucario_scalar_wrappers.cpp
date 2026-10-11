void operator delete(void*);
extern "C" void* fn_118_136B4(void*, short);
extern "C" void* fn_118_3888(void*, short);

extern "C" void* fn_118_13658(void* object, short deleting) {
    if (object != 0) {
        fn_118_136B4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_136B4(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_136F4(void* object, short deleting) {
    if (object != 0) {
        // The original base-subobject destruction retains its own null guard.
        if (object != 0) {
            fn_118_3888(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
