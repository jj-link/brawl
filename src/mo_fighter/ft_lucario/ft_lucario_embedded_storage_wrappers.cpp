void operator delete(void*);
extern "C" void* fn_118_3450(void*, short);
extern "C" void* fn_118_481C(void*, short);
extern "C" void* fn_118_34B0(void*, short);

extern "C" void* fn_118_33E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3450(storage + 0x40B8, -1);
        fn_118_481C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_3450(void* object, short deleting) {
    if (object != 0) {
        fn_118_34B0(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
