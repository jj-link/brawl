void operator delete(void*);
extern "C" void* fn_27_14CD30(void*, short);
extern "C" void* fn_27_5BFA0(void*, short);
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void* fn_27_C21DC(void*, short);
extern "C" void* fn_27_BED74(void*, short);

extern "C" void* fn_118_2BB0(void* object, short deleting) {
    if (object != 0) {
        fn_27_14CD30(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2C0C(void* object, short deleting) {
    if (object != 0) {
        fn_27_5BFA0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2C68(void* object, short deleting) {
    if (object != 0) {
        fn_27_1966BC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2CC4(void* object, short deleting) {
    if (object != 0) {
        fn_27_C21DC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2D20(void* object, short deleting) {
    if (object != 0) {
        fn_27_BED74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
