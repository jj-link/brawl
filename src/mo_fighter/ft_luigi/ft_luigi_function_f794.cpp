extern "C" void* fn_99_3E8C(void*, short);
extern "C" void* fn_99_F80C(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_99_F794(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_3E8C(storage + 0x8C, destroyMember);
        fn_99_F80C(storage + 0x20, destroyMember);
        fn_27_CD934(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
