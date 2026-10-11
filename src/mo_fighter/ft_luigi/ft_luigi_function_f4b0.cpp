extern "C" void* fn_99_3C6C(void*, short);

extern "C" void* fn_99_F4B0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_3C6C(storage + 0x38, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
