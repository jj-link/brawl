#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_125_794C(void*, short);
void* fn_125_79AC(void*, short);
}

extern "C" void* fn_125_78D4(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_125_794C(storage + 0x18, destroyMember);
        fn_125_79AC(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
