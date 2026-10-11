extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_99_FB28(void*, short);

extern "C" void* fn_99_FABC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_565F0(storage + 0x0c, destroyMember);
        fn_99_FB28(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
