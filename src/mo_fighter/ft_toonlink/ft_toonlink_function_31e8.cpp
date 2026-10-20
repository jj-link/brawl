#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_121_21E0(void*, short);
void* fn_121_2144(void*, short);
}

extern "C" void* fn_121_31E8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_121_21E0(storage + 0x18, destroyMember);
        fn_121_2144(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
