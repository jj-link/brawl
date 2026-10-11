extern "C" void* fn_99_F994(void*, short);
extern "C" void* fn_99_3F6C(void*, short);

extern "C" void* fn_99_F928(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_F994(storage + 0x24, destroyMember);
        fn_99_3F6C(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
