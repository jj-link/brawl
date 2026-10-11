void operator delete(void*);
extern "C" void* fn_118_3EB4(void*, short);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void* fn_118_3F14(void*, short);
extern "C" void* fn_118_3B70(void*, short);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_118_403C(void*, short);
extern "C" void* fn_118_407C(void*, short);

extern "C" void* fn_118_3E2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3EB4(storage + 0x8C, -1);
        if (storage + 0x20 != 0) {
            if (storage + 0x20 != 0) {
                if (storage + 0x20 != 0) {
                    fn_27_1A1E70(storage + 0x20, -1);
                }
            }
        }
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3EB4(void* object, short deleting) {
    if (object != 0) {
        fn_118_3F14(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3F14(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_3F54(void* object, short deleting) {
    if (object != 0) {
        fn_118_3B70(static_cast<unsigned char*>(object) + 0x14, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3FB4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_118_403C(storage + 0x24, 0);
        }
        fn_118_407C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
