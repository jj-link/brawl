#pragma force_active on
extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_27_198034(void*, short);
void fn_99_2D20(void*, short);
}

extern "C" void* fn_99_2CA0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B81C4(storage + 0xa4, destroyMember);
        fn_99_2D20(storage + 0x48, destroyMember);
        if (object) fn_27_198034(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
