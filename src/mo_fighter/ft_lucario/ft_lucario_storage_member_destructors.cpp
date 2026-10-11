void operator delete(void*);
extern "C" void* fn_27_63EBC(void*, short);
extern "C" void* fn_27_5C674(void*, short);
extern "C" void* fn_27_97968(void*, short);
extern "C" void* fn_27_1CCCC(void*, short);
extern "C" void* fn_118_3110(void*, short);
extern "C" void* fn_27_CBF58(void*, short);
extern "C" void* fn_118_3BCC(void*, short);

extern "C" void* fn_118_3A2C(void* object, short deleting) {
    if (object != 0) {
        fn_27_63EBC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3A88(void* object, short deleting) {
    if (object != 0) {
        fn_27_5C674(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3AE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_97968(storage + 0x58, -1);
        fn_27_1CCCC(storage + 0x48, -1);
        fn_118_3110(storage + 0x3C, -1);
        if (object != 0) {
            fn_27_CBF58(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3B70(void* object, short deleting) {
    if (object != 0) {
        fn_118_3BCC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3BCC(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
