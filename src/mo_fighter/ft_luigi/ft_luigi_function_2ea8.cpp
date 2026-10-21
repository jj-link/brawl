#pragma force_active on
extern "C" {
void* fn_27_CB048(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void* fn_27_197EF4(void*, short);
}

extern "C" void* fn_99_2EA8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_CB048(storage + 0x220, destroyMember);
        fn_27_199214(storage + 0x94, destroyMember);
        fn_27_A78FC(storage + 0x78, destroyMember);
        fn_27_14E050(storage + 0x10, destroyMember);
        if (object) fn_27_197EF4(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
