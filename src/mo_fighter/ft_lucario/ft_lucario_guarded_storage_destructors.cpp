void operator delete(void*);
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_118_3CA8(void*, short);
extern "C" void* fn_118_1F78(void*, short);
extern "C" void* fn_118_3CE8(void*, short);
extern "C" void* fn_118_1F1C(void*, short);
extern "C" void* fn_27_75E0C(void*, short);
extern "C" void* fn_27_64930(void*, short);
extern "C" void* fn_27_1A2B08(void*, short);

extern "C" void* fn_118_3C0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_118_3CA8(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_118_1F78(storage + 0x20, 0);
            fn_118_3CE8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3CA8(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_3CE8(void* object, short deleting) {
    if (object != 0) {
        fn_118_1F1C(static_cast<unsigned char*>(object) + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3D48(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_75E0C(storage + 0x4C, -1);
        if (storage + 0x20 != 0) {
            fn_27_64930(storage + 0x20, 0);
        }
        fn_118_1F1C(storage + 0x14, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3DCC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2B08(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
