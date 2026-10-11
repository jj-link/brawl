extern "C" void* fn_27_1A241C(void*, short);

extern "C" void* fn_99_F5C8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_1A241C(storage + 0x10, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
