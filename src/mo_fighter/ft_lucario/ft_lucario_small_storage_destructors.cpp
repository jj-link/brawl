void operator delete(void*);
extern "C" void* fn_118_3924(void*, short);
extern "C" void* fn_118_2298(void*, short);
extern "C" void* fn_118_21BC(void*, short);
extern "C" void* fn_27_C31CC(void*, short);

extern "C" void* fn_118_3888(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_38C8(void* object, short deleting) {
    if (object != 0) {
        fn_118_3924(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3924(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_3964(void* object, short deleting) {
    if (object != 0) {
        fn_118_2298(static_cast<unsigned char*>(object) + 0x50, -1);
        fn_118_21BC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_39D0(void* object, short deleting) {
    if (object != 0) {
        fn_27_C31CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
