extern "C" {
void* fn_27_B5324(void*, short);
void* fn_99_FD2C(void*, short);
void* fn_99_4034(void*, short);
}

extern "C" void* fn_99_FCA8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x20, destroyMember);
        fn_99_FD2C(storage + 0x10, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_99_4034(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
