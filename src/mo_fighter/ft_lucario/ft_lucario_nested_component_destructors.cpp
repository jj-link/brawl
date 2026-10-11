void operator delete(void*);
extern "C" void* fn_27_B81C4(void*, short);
extern "C" void* fn_118_2DFC(void*, short);
extern "C" void* fn_27_198034(void*, short);
extern "C" void* fn_27_19816C(void*, short);
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void* fn_27_ACC5C(void*, short);
extern "C" void* fn_27_10424(void*, short);
extern "C" void* fn_27_19A97C(void*, short);

extern "C" void* fn_118_2D7C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B81C4(storage + 0xA4, -1);
        fn_118_2DFC(storage + 0x48, -1);
        if (object != 0) {
            fn_27_198034(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2DFC(void* object, short deleting) {
    if (object != 0) {
        fn_27_19816C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2E58(void* object, short deleting) {
    if (object != 0) {
        fn_27_B64B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2EB4(void* object, short deleting) {
    if (object != 0) {
        fn_27_ACC5C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2F10(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 0x7C, -1);
        if (object != 0) {
            fn_27_19A97C(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
