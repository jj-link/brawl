#pragma force_active on
extern "C" {
void* fn_27_B21D0(void*, short);
void* fn_27_CB4A0(void*, short);
}

extern "C" void* fn_99_50A0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B21D0(storage + 0x50, destroyMember);
        if (object) fn_27_CB4A0(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
