#pragma force_active on
extern "C" {
void* fn_99_3034(void*, short);
void* fn_99_3090(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_99_2F9C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_97968(storage + 0x6c, destroyMember);
        fn_27_1CCCC(storage + 0x5c, destroyMember);
        fn_99_3034(storage + 0x50, destroyMember);
        fn_99_3090(storage + 0x38, destroyMember);
        if (object) fn_27_CBF58(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
