void operator delete(void*);
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_118_324C(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
extern "C" void* fn_118_32A8(void*, short);
extern "C" void* fn_118_3318(void*, short);
extern "C" void* fn_118_4DD8(void*, short);
extern "C" void* fn_118_3374(void*, short);
extern "C" void* fn_118_33E4(void*, short);
extern "C" void* fn_118_48E8(void*, short);

extern "C" void* fn_118_31C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x7FE0, -1);
        fn_118_324C(storage + 0x7C, -1);
        fn_27_19F4C4(storage + 0x20, -1);
        fn_27_1A55B0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_324C(void* object, short deleting) {
    if (object != 0) {
        fn_118_32A8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_32A8(void* object, short deleting) {
    if (object != 0) {
        fn_118_3318(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_118_4DD8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3318(void* object, short deleting) {
    if (object != 0) {
        fn_118_3374(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3374(void* object, short deleting) {
    if (object != 0) {
        fn_118_33E4(static_cast<unsigned char*>(object) + 0x1E4C, -1);
        fn_118_48E8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
