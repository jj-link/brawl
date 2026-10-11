void operator delete(void*);
extern "C" void* fn_118_3450(void*, short);
extern "C" void* fn_118_4888(void*, short);
extern "C" void* fn_118_49AC(void*, short);
extern "C" void* fn_118_4A0C(void*, short);

extern "C" void* fn_118_481C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3450(storage + 0x2060, -1);
        fn_118_4888(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_4888(void* object, short deleting) {
    if (object != 0) {
        fn_118_3450(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_48E8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_118_49AC(static_cast<unsigned char*>(object) + 0x4, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_494C(void* object, short deleting) {
    if (object != 0) {
        fn_118_49AC(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_49AC(void* object, short deleting) {
    if (object != 0) {
        fn_118_4A0C(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
