void operator delete(void*);

extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_117_2E3C(void*, short);
void* fn_27_1982AC(void*, short);
}

extern "C" void* fn_117_2DBC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_B81C4(members + 0xF4, memberDeleting);
        fn_117_2E3C(members + 0x98, memberDeleting);
        if (object != 0) {
            fn_27_1982AC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
