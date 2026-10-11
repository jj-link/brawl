void operator delete(void*);
extern "C" void* fn_118_3B70(void*, short);
extern "C" void* fn_118_A8A8(void*, short);
extern "C" void* fn_118_4F70(void*, short);
extern "C" void* fn_118_4FE0(void*, short);

extern "C" void* fn_118_4DD8(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_4E18(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_4E58(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_4E98(void* object, short deleting) {
    if (object != 0) {
        fn_118_3B70(static_cast<unsigned char*>(object) + 0x1C0, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_4EF8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_A8A8(storage + 0xE0, -1);
        fn_118_4F70(storage + 0x30, -1);
        fn_118_4FE0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
