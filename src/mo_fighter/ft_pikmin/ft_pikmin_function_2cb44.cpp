#pragma force_active on
extern "C" {
void* fn_113_B24(void*, short);
void fn_113_AC8(void*, short);
}

extern "C" void* fn_113_2CB44(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = 0;
        fn_113_B24(storage + 0x20, destroyMember);
        if (object) fn_113_AC8(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
