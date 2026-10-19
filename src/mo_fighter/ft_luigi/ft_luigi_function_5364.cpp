#pragma force_active on
extern "C" {
void fn_27_689B0(void*, short);
void fn_27_1985B4(void*, short);
}

extern "C" void* fn_99_5364(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_689B0(storage + 0x7c, destroyMember);
        if (object) fn_27_1985B4(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
