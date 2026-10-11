void operator delete(void*);
extern "C" void* fn_27_1A09B4(void*, short);
extern "C" void* fn_118_21BC(void*, short);
extern "C" void* fn_118_2258(void*, short);
extern "C" void* fn_118_2298(void*, short);
extern "C" void* fn_27_C7770(void*, short);

extern "C" void* fn_118_2360(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A09B4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_23BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_21BC(storage + 0xDC, -1);
        fn_118_2258(storage + 0xC0, -1);
        fn_118_2298(storage + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2448(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_21BC(storage + 0xDC, -1);
        fn_118_2258(storage + 0xC0, -1);
        fn_118_2298(storage + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_24D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_21BC(storage + 0xDC, -1);
        fn_118_2258(storage + 0xC0, -1);
        fn_118_2298(storage + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2560(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_21BC(storage + 0xDC, -1);
        fn_118_2258(storage + 0xC0, -1);
        fn_118_2298(storage + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
