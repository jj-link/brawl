extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_99_3034(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_99_F424(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_97968(storage + 0x58, destroyMember);
        fn_27_1CCCC(storage + 0x48, destroyMember);
        fn_99_3034(storage + 0x3c, destroyMember);
        if (object) fn_27_CBF58(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
