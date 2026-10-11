void operator delete(void*);
extern "C" void* fn_118_21BC(void*, short);
extern "C" void* fn_118_2258(void*, short);
extern "C" void* fn_118_2298(void*, short);
extern "C" void* fn_118_28B4(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void* fn_27_1A65F0(void*, short);

extern "C" void* fn_118_25EC(void* object, short deleting) {
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

extern "C" void* fn_118_2678(void* object, short deleting) {
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

extern "C" void* fn_118_2704(void* object, short deleting) {
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

extern "C" void* fn_118_2790(void* object, short deleting) {
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

extern "C" void* fn_118_281C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_21BC(storage + 0xA0C, -1);
        fn_118_2258(storage + 0x9F0, -1);
        fn_118_2298(storage + 0x944, -1);
        fn_118_28B4(storage + 0x4A0, -1);
        if (object != 0) {
            fn_27_1A65F0(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
