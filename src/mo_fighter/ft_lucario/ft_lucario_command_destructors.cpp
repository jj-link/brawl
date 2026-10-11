void operator delete(void*);
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void* fn_27_A0C74(void*, short);
extern "C" void* fn_118_2360(void*, short);

extern "C" void* fn_118_21BC(void* object, short deleting) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2218(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2258(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2298(void* object, short deleting) {
    if (object != 0) {
        fn_27_A0C74(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_22F4(void* object, short deleting) {
    if (object != 0) {
        fn_118_2360(static_cast<unsigned char*>(object) + 0x50, -1);
        fn_118_21BC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
