void operator delete(void*);
extern "C" void* fn_27_CB048(void*, short);
extern "C" void* fn_27_199214(void*, short);
extern "C" void* fn_27_A78FC(void*, short);
extern "C" void* fn_27_14E050(void*, short);
extern "C" void* fn_27_197EF4(void*, short);
extern "C" void* fn_27_14FCF4(void*, short);
extern "C" void* fn_27_97968(void*, short);
extern "C" void* fn_27_1CCCC(void*, short);
extern "C" void* fn_118_3110(void*, short);
extern "C" void* fn_118_316C(void*, short);
extern "C" void* fn_27_CBF58(void*, short);
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void* fn_27_19874C(void*, short);

extern "C" void* fn_118_2F84(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_CB048(storage + 0x220, -1);
        fn_27_199214(storage + 0x94, -1);
        fn_27_A78FC(storage + 0x78, -1);
        fn_27_14E050(storage + 0x10, -1);
        if (object != 0) {
            fn_27_197EF4(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_301C(void* object, short deleting) {
    if (object != 0) {
        fn_27_14FCF4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3078(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_97968(storage + 0x6C, -1);
        fn_27_1CCCC(storage + 0x5C, -1);
        fn_118_3110(storage + 0x50, -1);
        fn_118_316C(storage + 0x38, -1);
        if (object != 0) {
            fn_27_CBF58(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3110(void* object, short deleting) {
    if (object != 0) {
        fn_27_A0C34(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_316C(void* object, short deleting) {
    if (object != 0) {
        fn_27_19874C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
