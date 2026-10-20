#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_107_7F38(void*, short);
void* fn_107_7F98(void*, short);
}

extern "C" void* fn_107_7EC0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_107_7F38(storage + 0x18, destroyMember);
        fn_107_7F98(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
